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

#define EPS 1e-9

int main(){
    double lg2 = log(2);
    int TC,CC = 1;
    long long n;
    cin >> TC;
    while(TC--){
        cin >> n;
        printf("Case %d: %.0lf\n",CC++,floor(log(n+1)/lg2 - EPS)+1);
    }
    return 0;
}
