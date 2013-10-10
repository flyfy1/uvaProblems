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

using namespace std;

typedef pair<int,int>   ii;
typedef vector<int>     vi;
typedef vector<ii>      vii;

int val[] = {1,5,10,25,50};

long long memo[5][30005];

long long cal(int p,int n){
    if(n == 0)  return 1;
    if(n < 0 || p >= 5)   return 0;
    if(memo[p][n] != -1)    return memo[p][n];
    long long res = 0;
    for(int i=0;n >= i*val[p]; i++)  res += cal(p+1,n - i*val[p]);
    return memo[p][n] = res;
}

int main(){
    int N;
    for(int i=0;i<5;i++)for(int j=0;j<30005;j++)    memo[i][j] = -1;
    while(scanf("%d",&N) == 1){
        long long res = cal(0,N);
        if(res == 1)    printf("There is only 1 way to produce %d cents change.\n",N);
        else printf("There are %lld ways to produce %d cents change.\n",res,N);
    }
    return 0;
}
