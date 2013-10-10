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


bool testN(int res,int n){
    if(n == 0)  return false;
    for(int i=0;i<n;i++){
        if( (res-1) % n)    return false;
        res = (res-1) / n * (n-1);
    }
    if(res % n) return false;
    return true;
}

int main(){
    int N;
    while(cin >> N, N >= 0){
        int val = -1;
        int nh = ceil(sqrt(N));
        for(int i=nh;i>1;i--){
            if(testN(N,i)){
                val = i;
                break;
            }
        }
        printf("%d coconuts, ",N);
        if(val != -1)   printf("%d people and 1 monkey\n",val);
        else printf("no solution\n");
    }
    return 0;
}
