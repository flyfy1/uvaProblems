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
#define MAX_V 51
#define INF 0x7fffffff

using namespace std;

typedef pair<int,int>   ii;
typedef vector<int>     vi;
typedef vector<ii>      vii;
typedef vector<vi>     vvi;
typedef vector<vii>    vvii;

int res[MAX_V][MAX_V],mf,f,s,t;
int oldMap[MAX_V][MAX_V];
vi p;
vii cuts;
bool isInS[MAX_V];

void augment(int v,int minEdge){
    if(v == s){
        f = minEdge; return;
    } else if(p[v] != -1){
        augment(p[v],min(minEdge,res[p[v]][v]));
        res[p[v]][v] -= f; res[v][p[v]] += f;
    }
}

int main(){
    int N,M;
    int a,b,c;
    while(cin >> N >> M, N || M){
        memset(res,0,sizeof res);
        memset(oldMap,0,sizeof oldMap);
        cuts.clear();

        for(int i=0;i<M;i++){
            cin >> a >> b >> c;
            a--;b--;
            res[a][b] =res[b][a] = c;
            oldMap[a][b] =oldMap[b][a] = c;
        }

        s = 0; t = 1;
        mf = 0;
        while(1){
            f = 0;

            // run BFS
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
        memset(isInS,0,sizeof isInS);
        queue<int> q; q.push(s);
        isInS[s] = 1;
        while(!q.empty()){
            int u = q.front(); q.pop();
            for(int i = 0;i<N;i++){
                if(res[u][i] && !isInS[i]){
                    isInS[i] = true;
                    q.push(i);
                }
            }
        }

        for(int i=0;i<N;i++){
            for(int j=0;j<N;j++){
                if(oldMap[i][j] && !res[i][j] && isInS[i] && !isInS[j]){
                    printf("%d %d\n",i+1,j+1);
                }
            }
        }
        cout << endl;
    }

    return 0;
}
