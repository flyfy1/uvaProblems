#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#include <set>
#include <stack>
#include <map>
#include <list>
#include <cmath>

using namespace std;

typedef pair<int,int>   ii;
typedef vector<int>     vi;
typedef vector<ii>      vii;
typedef vector<vi>     vvi;
typedef vector<vii>    vvii;
typedef map<int,int>    mii;
typedef unsigned long long ull;

int N,X;
unsigned long long tbl[26][150];

unsigned long long cal(int m,int k){
    if(m == N)  return k <= 0;
    if(k < 0)   return pow(6,N-m);
    if(tbl[m][k] != -1) return tbl[m][k];

    tbl[m][k] = 0;
    for(int i = 0; i < 6; i++){
        tbl[m][k] += cal(m+1,k-i);
    }
    return tbl[m][k];
}

unsigned long long gcd(ull a, ull b){
    ull r;
    while(b != 0){
        r = a % b; a = b; b = r;
    }
    return a;
}

int main(){
    unsigned long long a,b;
    while(cin >> N >> X, N || X){
        for(int i=0;i<25;i++)   for(int j=0;j<150;j++)  tbl[i][j] = -1;
        a = cal(0,X-N);
        b = round(pow(6,N));
        ull c = gcd(a,b);
        ull na = a/c; ull nb = b/c;
        if(na == 0) cout << 0 << endl;
        else if(nb == 1)    cout << na << endl;
        else cout << na << "/" << nb << endl;
    }
    return 0;
}
