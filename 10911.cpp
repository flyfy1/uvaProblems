#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>

using namespace std;

int N;
double dist[20][20],memo[1<<16];
double matching(int bitmask){
    if(memo[bitmask] > -0.5){
        return memo[bitmask];
    }
    if(bitmask == ((1 << (2*N)) - 1)){
        return memo[bitmask] = 0;
    }

    double ans = 20000000000.0;
    for(int p1 = 0; p1 < 2 * N; p1++){
        if(!(bitmask & (1 << p1))){
            for(int p2 = p1 + 1; p2 < 2 * N; p2++){
                if(!(bitmask & (1 << p2))){
                    ans = min(ans,dist[p1][p2] + matching(bitmask | (1 << p1) | (1 << p2)));
                }
            }
            break;
        }
    }

    return memo[bitmask] = ans;
}

int main(){
    char line[1000], name[1000];
    int i,j, caseNo = 1, x[20], y[20];
    while(sscanf(fgets(line,999,stdin),"%d",&N),N){
        for(i = 0;i<2*N;i++)    sscanf(fgets(line,999,stdin),"%*s %d %d",&x[i],&y[i]);
        for(i = 0;i<2*N;i++)    for(j=0;j<2*N;j++)  dist[i][j] = hypot((double) x[i] - x[j], (double) y[i] - y[j]);
        
        memset(memo,-1,sizeof memo);
        // int msize = 1 << (2*N);
        // for(int i=0;i<msize;i++)    memo[i] = -1;

        printf("Case %d: %.2lf\n",caseNo++,matching(0));
    }
    return 0;
}
