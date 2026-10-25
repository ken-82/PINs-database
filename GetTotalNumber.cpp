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
int cnt[N];

int main(){
    string path = "HIBP "+to_string(DIG)+" digit.txt";
    ifstream fin(path);
    string line;
    int q = 0;
    long long sum = 0;
    while(getline(fin,line)){
        sum += stoi(line.substr(DIG+1));
        q++;
        if(__builtin_popcount(q) == 1) cout << "Finished loop : " << q << '\n';
    }
    cout << sum;
}
//g++ .\GetTotalNumber.cpp -o GettotalNumber