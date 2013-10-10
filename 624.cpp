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

int M;  // num of tracks
int N;  // minutes

int v[22];

int coundTNum(int n){
    int co = 0;
    for(int i=0;i<M;i++){
        if(n & 1<<i)    co++;
    }
    // printf("n = %x, res = %d\n",n,co);
    return co;
}

int countCost(int n){
    int ss = 0;
    for(int i=0;i<M;i++){
        if(n & 1<<i)    ss += v[i];
    }
    return ss;
}

int main(){
    string buf;
    while(scanf("%d%d",&N,&M) == 2){
        for(int i=0;i<M;i++)    scanf("%d",&v[i]);
        int lim = 1 << M;
        int maxTime = 0,maxTrack = 0,state = 0;
        for(int i=0;i<lim;i++){
            int tUsed = countCost(i);
            int tTrack = coundTNum(i);
            if(tUsed > N)   continue;
            if(tUsed > maxTime){
                maxTrack = tTrack;
                maxTime = tUsed;
                state = i;
            } else if(tUsed == maxTime && maxTrack < tTrack){
                maxTrack = tTrack;
                state = i;
            }
        }

        for(int i=0;i<M;i++){
            if(state & 1<<i)    printf("%d ",v[i]);
        }
        printf("sum:%d\n",maxTime);
    }

    return 0;
}
