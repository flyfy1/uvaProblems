// Referred to: http://www.cnblogs.com/staginner/archive/2011/12/19/2293717.html

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


long long N;

void solve(){
    long long k,x,y;
    char b[20];
    sprintf(b,"%d",N);
    for(k = strlen(b) + 1; ; k++){
        x = (long long ) (log2(N) + k * log2(10));
        y = (long long ) (log2(N+1) + k * log2(10));
        if(x != y){
            printf("%d\n",y);
            break;
        }
    }
}

int main(){
    while(cin >> N){
        solve();
    }

    return 0;
}
