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
#define EPS 1e-8

typedef pair<int,int>   ii;
typedef vector<int>     vi;
typedef vector<ii>      vii;
typedef vector<vi>     vvi;
typedef vector<vii>    vvii;
typedef map<int,int>    mii;


int main(){
    int m,k;
    while(cin >> m >> k, m || k){
        if(k == 0 || k == 100){
            printf("Not found\n");
            continue;
        } 
        double mm = m;
        double v = 100 * (mm-1) / (100 - k);
        long long t = floor(v);
        if(v > t + EPS){
            v = t;
        } else{
            v = v-1;
        }
        long long res = v;
        if(v < m){
            printf("Not found\n");
        } else{
            printf("%lld\n",res);
        }
    }

    return 0;
}
