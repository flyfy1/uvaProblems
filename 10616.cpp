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

vi v;
int N,Q;
int M,D;

int memo[22][210][12];

int cal(int s,int p,int l){
    if( v.size() - p  < l)   return 0;  // the case where cannot finish selection
    s = ((s + v[p]) % D + D) % D;
    if(memo[s][p][l] != -1){
        return memo[s][p][l];
    }
    int res = 0;
    if(l == 0 ) res = (s == 0);
    else{
        for(int i= p+1;i<v.size();i++)  res += cal(s,i,l-1);
    }

    return memo[s][p][l] = res;
}

int main(){
    int CC=1;
    while(scanf("%d%d",&N,&Q),N||Q){
        cout << "SET " << CC++ << ":" << endl;
        //printf("N = %d, Q= %d\n",N,Q);
        v = vi(N);
        for(int i=0;i<N;i++)    scanf("%d",&v[i]);
        
        for(int i=0;i<Q;i++){
            scanf("%d%d",&D,&M);
            for(int l=0;l<D;l++) for(int j=0;j<=N;j++)  for(int k=0;k<=M;k++)   memo[l][j][k] = -1;
            int RES = 0;
            for(int j=0;j<N;j++){
                RES += cal(0,j,M-1);
            }
            cout << "QUERY " << i+1 << ": " << RES << endl;
        }
    }

    return 0;
}
