#include <iostream>
#include <fstream>
#include <map>
#include <string>
#include <algorithm>
#include <vector>
#include <iomanip>

using namespace std;
using pii = pair<int,int>;

#define all(x) begin(x),end(x)
#define f first
#define s second

int constexpr DIG = 6;
int constexpr pow_10[] = {1,10,100,1000,10000,100000,1000000,10000000,100000000};

int constexpr N = pow_10[DIG];
int cnt[N];

int main(){
    string pathin = "HIBP "+to_string(DIG)+" digit.txt";
    ifstream fin(pathin);
    string line;
    int q = 0;
    int sum = 0;
    while(getline(fin,line)){
        int pref = stoi(line.substr(0,DIG));
        int suff = stoi(line.substr(DIG+1));
        cnt[pref] = suff;
        sum += suff;
        q++;
        if(__builtin_popcount(q) == 1) cout << "Finished loop : " << q << '\n';
    }
    cout << "Finished Loading\n";
    sort(cnt,cnt+N,greater<int>());
    cout << "Finished sorting\n";
    string pathout = "Visualization/HIBP_"+to_string(DIG)+"_Percent.txt";
    ofstream fout(pathout);
    int prefsum = 0;
    for(int i{};i < N;i++){
        prefsum += cnt[i];
        fout << i << ":";
        fout << fixed << setprecision(10) << ((double)prefsum)/((double)sum) << '\n';
    }
}
//g++ .\Visualization\Generate_Percent.cpp -o .\Visualization\Generate_Percent.exe