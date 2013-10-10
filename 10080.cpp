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
#define MAX_V 204        // num of vertexes
#define INF 0x7fffffff

using namespace std;

typedef pair<int,int>   ii;
typedef pair<double,double>   dfdf;
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

double sq(double x){return x*x;}
double dis(dfdf x,dfdf y){   return sqrt(sq(x.first - y.first) + sq(x.second - y.second));}

int main(){
    int M,N;
    double S,V;
    while(cin >> N >> M >> S >> V){
        memset(res,0,sizeof res);
        vector<pair<double,double> > G,H;
        double x,y;
        for(int i=0;i<N;i++){
            cin >> x >> y;
            G.push_back(make_pair(x,y));
        }
        for(int i=0;i<M;i++){
            cin >> x >> y;
            H.push_back(make_pair(x,y));
        }

        
        double dd = S*V;

        for(int i=0;i<N;i++){
            for(int j=0;j<M;j++){
                if(dis(G[i],H[j]) <= dd)   res[1+i][N+1+j] = 1;
            }
        }
        s = 0;t = M + N + 1;
        for(int i=0;i<N;i++){
            res[s][1+i] = 1;
        }
        for(int i=0;i<M;i++){
            res[t-i-1][t] = 1;
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
        cout << N - mf << endl;
    }
    return 0;
}
