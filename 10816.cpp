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

#define IMAX 0x7fff
#define DMAX 1e10
#define EPS 1e-8
#define DMSIZE 105

using namespace std;

typedef pair<int,int>   ii;
typedef vector<int>     vi;
typedef vector<ii>      vii;
typedef vector<vi>     vvi;
typedef vector<vii>    vvii;
typedef map<int,int>    mii;

int N,E;
int S,T;
double dis[DMSIZE][DMSIZE],apspt[DMSIZE][DMSIZE],apspd[DMSIZE][DMSIZE];
int p[DMSIZE][DMSIZE];

int main(){
    while(cin >> N >> E >> S >> T){
        vi va,vb;
        vector<double> vd,vt;
        for(int i=0;i<DMSIZE;i++){
            for(int j=0;j<DMSIZE;j++){
                apspt[i][j] = DMAX;
            }
        }
        memset(p,-1,sizeof p);

        S--; T--;
        int a,b;
        double t,d;

        // first step -- find out the lowest temperature
        for(int i=0;i<E;i++){
            cin >> a >> b >> t >> d;
            a--;b--;
            va.push_back(a);
            vb.push_back(b);
            vt.push_back(t);
            vd.push_back(d);
            if(t < apspt[a][b]){
                apspt[b][a] = t;
                apspt[a][b] = t;
            }
        }

        for(int k=0;k<N;k++){
            for(int i=0;i<N;i++){
                for(int j=0;j<N;j++){
                    double mt = max(apspt[i][k],apspt[j][k]);
                    if(mt < apspt[i][j]){
                        apspt[i][j] = mt;
                    } 
                }
            }
        }
        double minT = apspt[S][T];

        for(int i=0;i<DMSIZE;i++){
            for(int j=0;j<DMSIZE;j++){
                dis[i][j] = DMAX;
                apspd[i][j] = DMAX;
                apspt[i][j] = DMAX;
            }
        }

        // second step -- find out the lowest distance
        for(int i=0;i<E;i++){
            a = va[i]; b=vb[i]; t=vt[i]; d=vd[i];
            if(t < minT + EPS && d < dis[a][b]){
                dis[a][b] = dis[b][a] = d;
                apspd[a][b] = apspd[b][a] = d;
                p[a][b] = a;
                p[b][a] = b;
            }
        }

        for(int k=0;k<N;k++){
            for(int i=0;i<N;i++){
                for(int j=0;j<N;j++){
                    double sd = apspd[i][k]+apspd[j][k];
                    if(sd < apspd[i][j]){
                        apspd[i][j] = sd;
                        p[i][j] = k;
                    }
                }
            }
        }

        stack<int> st;int cp = T;
        while(cp != S && p[S][cp] != -1){
            st.push(cp);
            cp = p[S][cp];
        }
        printf("%d",S+1);
        while(!st.empty()){
            printf(" %d",st.top()+1);
            st.pop();
        }
        putchar('\n');

        printf("%.1lf %.1lf\n",apspd[S][T],minT);
    }
    return 0;
}
