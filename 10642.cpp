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

long long getSteps(long long a,long long b){
    long long p = a+b;
    return p*(p+1)/2 + a;
}

int main(){
    long long a,b,tc;
    long long sa,sb;
    int CC = 1;
    cin >> tc;
    while(tc--){
        cin >> a >> b;
        sa = getSteps(a,b);
        cin >> a >> b;
        sb = getSteps(a,b);
        printf("Case %d: %lld\n",CC++,sb - sa);
    }
    return 0;
}
