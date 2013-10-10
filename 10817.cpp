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
#define MAX 0x7f7fffff
#define MAXS 8
#define MAXN 103

using namespace std;

typedef pair<int,int>   ii;
typedef vector<int>     vi;
typedef vector<ii>      vii;

int states[MAXN][1<<2*MAXS];
int S,M,N;
vii applicants;  // first: cost; second: module can teach, bit mask, one bit for one module
vii current;
int sFinal;

int getNewState(int s,int module){
    for(int i=0;i<S;i++){
        if(module & (1<<i)){
            if(s & 1<<(2*i)) s |= 1<<(2*i+1);
            else  s |= 1<<(2*i);
        }
    }
    return s;
}

// return: the new state on can relax
// 0 on cannot
int relax(int s,int oidx, int nidx){
    ii A = applicants[nidx];
    int ns = getNewState(s,A.second);

    if(states[oidx][s] + A.first >= states[nidx][ns]) return 0;
    states[nidx][ns] = states[oidx][s] + A.first;
    //printf("nCost: %d, oldCost: %d, cost: %d,os = %x, ns = %x, oidx=%d, nidx = %d\n",
            //states[nidx][ns],states[oidx][s],C,s,ns,oidx,nidx);
    return ns;
}

int main(){
    string buf;
    while(cin >> S >> M >> N, S){
        current = vii(M);
        int C,t;
        getline(cin,buf);
        for(int i=0;i<M;i++){
            getline(cin,buf);
            istringstream in(buf);
            in >> C;
            int module = 0;
            while(in >> t){
                module |= 1<<(t-1);
            }
            current[i] = ii(C,module);
        }
        applicants = vii(N+1);
        for(int i=1;i<=N;i++){
            getline(cin,buf);
            istringstream in(buf);
            in >> C;
            int module = 0;
            while(in >> t){
                module |= 1<<(t-1);
            }
            applicants[i] = ii(C,module);
        }

        for(int i=0;i<MAXN;i++){
            for(int j=0;j<1<<(2*MAXS);j++){
                states[i][j] = MAX;
            }
        }
        
        sFinal = 0;
        for(int i=0;i< S;i++){sFinal <<= 2; sFinal |= 3;}
        int sStart = 0;
        int sCost = 0;
        for(int i=0;i< M;i++){
            sStart = getNewState(sStart,current[i].second);
            sCost += current[i].first;
        }
        // cout << "sCost: " << sCost << endl;
        states[0][sStart] = 0;
        queue<ii> qs; qs.push(ii(sStart,0)); // first is the state, second is the applicant index hired
        int ns = 0;
        while(!qs.empty()){
            ii fs = qs.front(); qs.pop();
        //    printf("-- fs = %x, idx = %d, cost = %d\n",fs.first,fs.second,states[fs.second][fs.first]);
            for(int i=fs.second + 1; i<=N;i++){
                if(ns=relax(fs.first,fs.second,i))   qs.push(ii(ns,i));
            }
            // if(fs.first & 1<<6*2) cout << "-- end - fs contains 7" << endl;
        }
        int mmin = MAX;
        for(int i=0;i<=N;i++)   mmin = min(states[i][sFinal],mmin);
        // printf("fs = %x, fs cost:%d, is cost: %d\n",sFinal,mmin,sCost);
        cout << mmin + sCost << endl;
    }
    
    return 0;
}
