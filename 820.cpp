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
#define MAX_V 101        // num of vertexes
#define INF 0x7fffffff

using namespace std;

typedef pair<int,int>   ii;
typedef vector<int>     vi;
typedef vector<ii>      vii;
typedef vector<vi>     vvi;
typedef vector<vii>    vvii;

int res[MAX_V][MAX_V],mf,f,s,t;
vi p;

void augment(int v,int minEdge){
    if(v == s){
        f = minEdge; return;
    } else if(p[v] != -1){
        augment(p[v],min(minEdge,res[p[v]][v]));
        res[p[v]][v] -= f; res[v][p[v]] += f;
    }
}

int main(){
    int CC = 1, N;
    while(cin >> N, N){
        memset(res,0,sizeof res);
        int u,v,n,c;
        cin >> u >> v >> n;
        s = u-1; t = v-1;
        for(int i=0;i<n;i++){
            cin >> u >> v >> c;
            u--;v--; res[u][v] += c; res[v][u] += c;
        }

        mf = 0;
        while(1){
            f = 0;

            vi dist(MAX_V,INF); dist[s] = 0; queue<int> q; q.push(s);
            p.assign(MAX_V,-1);
            while(!q.empty()){
                int u = q.front(); q.pop();
                if(u == t)  break;
                for(int v=0;v<MAX_V;v++){
                    if(res[u][v] > 0 && dist[v] == INF) dist[v] = dist[u] + 1, q.push(v), p[v] = u;
                }
            }
            augment(t,INF);
            if(f == 0)  break;
            mf += f;
        }
        printf("Network %d\nThe bandwidth is %d.\n\n",CC++,mf);
    }
    return 0;
}
