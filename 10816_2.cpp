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
#define MAXN 105
#define MAXELE 10005
#define EPS 1e-5

using namespace std;

typedef pair<int,int>   ii;
typedef vector<int>     vi;
typedef vector<ii>      vii;
typedef vector<vi>     vvi;
typedef vector<vii>    vvii;
typedef map<int,int>    mii;
typedef pair<double,int>    di;

int uarr[MAXELE],varr[MAXELE];
double tarr[MAXELE],darr[MAXELE];
double tmap[MAXN][MAXN],dmap[MAXN][MAXN],dist[MAXN];
int N,E,S,T;

int main(){
    int u,v;
    double t,d;
    while(scanf("%d%d",&N,&E) == 2){
        cin >> S >> T;S--;T--;
        for(int i=0;i<E;i++){
            scanf("%d%d%lf%lf",&u,&v,tarr+i,darr+i);
            u--; v--;
            uarr[i] = u; varr[i] = v;
        }

        // first, find the min T
        double minT = 1e10;
        for(int i=0;i<MAXN;i++)
            for(int j=0;j<MAXN;j++){
                tmap[i][j] = 1e10;
                dmap[i][j] = 1e10;
            }
        for(int i=0;i<E;i++){
            if(tarr[i] < tmap[uarr[i]][varr[i]])
                tmap[uarr[i]][varr[i]] = tmap[varr[i]][uarr[i]] = tarr[i];
        }

        // use adj list
        vector<vector<di> > adjList(N);
        for(int i=0;i<N;i++){
            for(int j=0;j<N;j++){
                if(tmap[i][j] < 1e9)    adjList[i].push_back(di(tmap[i][j],j));
            }
        }

        for(int i=0;i<N;i++)    dist[i] = 1e10;
        priority_queue<di,vector<di>,greater<di> > q;
        q.push(di(0,S)); dist[S] = 0;
        while(!q.empty()){
            di un = q.top(); q.pop();
            if(un.second == T){
                minT = un.first;
                break;
            }
            for(int i=0;i<adjList[un.second].size();i++){
                di vn = adjList[un.second][i];
                vn.first = max(vn.first,un.first);
                if(vn.first < dist[vn.second]){
                    dist[vn.second] = vn.first;
                    q.push(vn);
                }
            }
        }

        // then calculate the distance
        adjList.clear();
        for(int i=0;i<N;i++)    adjList.push_back(vector<di>());
        for(int i=0;i<E;i++){
            if(tarr[i] < minT + EPS && darr[i] < dmap[uarr[i]][varr[i]])
                dmap[uarr[i]][varr[i]] = dmap[varr[i]][uarr[i]] = darr[i];
        }
        for(int i=0;i<N;i++){
            for(int j=0;j<N;j++){
                if(dmap[i][j] < 1e9)    adjList[i].push_back(di(dmap[i][j],j));
            }
        }
        int p[N];
        for(int i=0;i<N;i++){
            dist[i] = 1e10;
            p[i] = -1;
        }
        priority_queue<di,vector<di>,greater<di> > qd;
        qd.push(di(0,S)); dist[S] = 0;
        double dis = -1;
        while(!qd.empty()){
            di u = qd.top(); qd.pop();
            if(u.second == T){
                dis = u.first; break;
            }
            for(int i=0;i<adjList[u.second].size();i++){
                di v= adjList[u.second][i];
                v.first = dist[u.second] + v.first;
                if(v.first < dist[v.second]){
                    dist[v.second] = v.first;
                    p[v.second] = u.second;
                    qd.push(v);
                }
            }
        }
        stack<int> st;int ct = T;
        while(p[ct] != -1){
            st.push(ct);
            ct = p[ct];
        }
        printf("%d",S+1);
        while(!st.empty()){
            printf(" %d",st.top()+1);
            st.pop();
        }
        putchar('\n');

        printf("%.1lf %.1lf\n",dis,minT);
    }

    return 0;
}
