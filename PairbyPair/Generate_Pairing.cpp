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

int constexpr DIG = 8;
int constexpr pow_10[] = {1,10,100,1000,10000,100000,1000000,10000000,100000000};

int constexpr N = pow_10[DIG];
int cnt[100];

int main(){
    string pathin = "HIBP "+to_string(DIG)+" digit.txt";
    ifstream fin(pathin);
    string line;
    int q = 0;
    while(getline(fin,line)){
        string pref = line.substr(0,DIG);
        int suff = stoi(line.substr(DIG+1));
        for(int i{};i < DIG-1;i++) cnt[(pref[i]-'0')*10+(pref[i+1]-'0')] += suff;
        q++;
        if(__builtin_popcount(q) == 1) cout << "Finished loop : " << q << '\n';
    }
    cout << "Finished\n";
    string pathout = "PairbyPair/HIBP_"+to_string(DIG)+"_PairCount.txt";
    ofstream fout(pathout);
    for(int i{};i < 100;i++){
        fout << setw(2) << setfill('0') << i;
        fout << " " << cnt[i] << '\n';
    }
}
//g++ .\PairbyPair\Generate_Pairing.cpp -o .\PairbyPair\Generate_Pairing.exe