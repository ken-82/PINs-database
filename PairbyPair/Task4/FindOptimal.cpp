#include <iostream>
#include <fstream>
#include <map>
#include <string>
#include <algorithm>
#include <vector>
#include <iomanip>

using namespace std;
using pii = pair<int,int>;
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

ll dp[DIG+1][10];//minimum cost ending string with j with size of i
int back[DIG+1][10];

int main(){
    read();
    for(int i{};i <= DIG;i++){
        for(int j{};j < 10;j++) dp[i][j] = INF;
    }
    for(int i{};i < 10;i++) dp[1][i] = 0;
    for(int k{2};k <= DIG;k++){
        for(int i{};i < 10;i++){
            for(int j{};j < 10;j++){
                int nwcost = dp[k-1][j]+cost[j][i];
                if(dp[k][i] > nwcost){
                    dp[k][i] = nwcost;
                    back[k][i] = j;
                }
            }
        }
    }
    pii ans = {dp[DIG][0],0};
    for(int i{1};i < 10;i++) ans = min(ans,{dp[DIG][i],i});
    int cur = ans.s;
    vector<int> pass = {cur};
    int at = DIG;
    while(at > 1){
        cur = back[at--][cur];
        pass.emplace_back(cur);
    }
    reverse(all(pass));
    for(auto k:pass) cout << k;
}
//g++ .\PairbyPair\Task4\FindOptimal.cpp -o .\PairbyPair\Task4\FindOptimal.exe