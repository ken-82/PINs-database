#include <iostream>
#include <fstream>
#include <map>
#include <string>
#include <algorithm>
#include <vector>
#include <iomanip>

using namespace std;
using pii = pair<int,int>;
using piii = tuple<int,int,int>;
using ll =  long long;

#define all(x) begin(x),end(x)
#define f first
#define s second

int constexpr DIG = 8;
int constexpr pow_10[] = {1,10,100,1000,10000,100000,1000000,10000000,100000000};

int cost[10][10];//weight of edge from i to j

void read(){
    string pathin = "PairbyPair/HIBP_"+to_string(DIG)+"_PairCount.txt";
    ifstream fin(pathin);
    string line;
    while(getline(fin,line)){
        int fr = line[0]-'0';
        int sd = line[1]-'0';
        int suff = stoi(line.substr(3));
        cost[fr][sd] = suff;
    }
}

ll const INF = 1e18+10;

ll dp[DIG+1][10][1<<10];//minimum cost ending string with j with size of i and using [mask] digits
int back[DIG+1][10][1<<10];

int main(){
    read();
    for(int i{};i <= DIG;i++){
        for(int j{};j < 10;j++){
            for(int mask{};mask < (1<<10);mask++) dp[i][j][mask] = INF;
        }
    }
    for(int i{};i < 10;i++) dp[1][i][1<<i] = 0;
    for(int k{2};k <= DIG;k++){
        for(int i{};i < 10;i++){
            for(int mask{};mask < (1<<10);mask++){
                if(__builtin_popcount(mask) != k || !(mask&(1<<i))) continue;
                for(int j{};j < 10;j++){
                    if(i == j) continue;
                    if(!(mask&(1<<j))) continue;
                    ll nwcost = dp[k-1][j][mask^(1<<i)]+cost[j][i];
                    if(dp[k][i][mask] > nwcost){
                        dp[k][i][mask] = nwcost;
                        back[k][i][mask] = j;
                    }
                }
            }
        }
    }
    tuple<ll,int,int> ans = {INF,0,0};
    for(int i{};i < 10;i++){
        for(int mask{};mask < (1<<10);mask++) ans = min(ans,{dp[DIG][i][mask],i,mask});
    }
    int curi = get<1>(ans);
    int curmask = get<2>(ans);
    vector<int> pass = {curi};
    int at = DIG;
    while(at > 1){
        int prev = back[at--][curi][curmask];
        curmask ^= (1<<curi);
        curi = prev;
        pass.emplace_back(curi);
    }
    reverse(all(pass));
    for(auto k:pass) cout << k;
}
//g++ .\PairbyPair\Task4\FindOptimal-Distict.cpp -o .\PairbyPair\Task4\FindOptimal-Distict.exe