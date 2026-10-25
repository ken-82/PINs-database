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
int constexpr HD = 50;
int constexpr pow_10[] = {1,10,100,1000,10000,100000,1000000,10000000,100000000};

int constexpr N = pow_10[DIG];
int cnt[N];

int main(){
    string path = "HIBP "+to_string(DIG)+" digit.txt";
    ifstream fin(path);
    string line;
    int q = 0;
    while(getline(fin,line)){
        int pref = stoi(line.substr(0,DIG));
        int suff = stoi(line.substr(DIG+1));
        cnt[pref] = suff;
        q++;
        if(__builtin_popcount(q) == 1) cout << "Finished loop : " << q << '\n';
    }
    cout << "Finished Loading\n";
    vector<pii> vc;
    for(int i{};i < N;i++) vc.emplace_back(cnt[i],i);
    cout << "Finished placing to vc\n";
    int hd = min(HD,(int)vc.size());
    nth_element(vc.begin(),vc.begin()+hd,vc.end(),greater<pii>());
    sort(vc.begin(),vc.begin()+hd,greater<pii>());
    string pathout = "HIBP_"+to_string(DIG)+"_top"+to_string(hd)+".txt";
    ofstream fout(pathout);
    for(int i{};i < hd;i++){
        fout << "Top " << i+1 << " : ";
        fout << setw(DIG) << setfill('0') << vc[i].s;
        fout << " - " << vc[i].f << '\n';
    }
    cout << "Finished all process";
}
//g++ .\Findtop20.cpp -o Findtop20.exe