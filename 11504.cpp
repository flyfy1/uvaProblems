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

#define DFS_WHITE   -1
#define DFS_BLACK   1
#define DFS_GRAY    2

using namespace std;

typedef pair<int,int>   ii;
typedef vector<int>     vi;
typedef vector<ii>      vii;


int V;
int dfsNumberCounter=1, numSCC;
vector<int> dfs_num, dfs_low,visited;
stack<int> S;

vector<vii> AdjList;
vector<vi>  Res;

void tarjanSCC(int u){
    dfs_low[u] = dfs_num[u] = dfsNumberCounter++;
    S.push(u);
    visited[u] = 1;
    for(int j = 0; j < (int) AdjList[u].size(); j++){
        ii v = AdjList[u][j];
        if(dfs_num[v.first] == DFS_WHITE)   tarjanSCC(v.first);
        if(visited[v.first])    dfs_low[u] = min(dfs_low[u],dfs_low[v.first]);
    }
    if(dfs_low[u] == dfs_num[u]){
        Res.push_back(vi());
        while(1){
            int v = S.top(); S.pop(); visited[v] = 0;
            Res[numSCC].push_back(v);
            if(S.empty() || u == v) break;
        }
        numSCC++;
    }
}

vi mmm;
vi vl;

int main(){
    int TC;
    int M;
    scanf("%d",&TC);
    while(TC--){
        scanf("%d%d",&V,&M);
        dfs_num.assign(V,DFS_WHITE); dfs_low.assign(V,0); visited.assign(V,0);
        dfsNumberCounter = numSCC = 0;
        AdjList = vector<vii>(V);
        Res = vector<vi>();
        int a,b;
        for(int i=0;i<M;i++){
            scanf("%d%d",&a,&b);
            if(a == b) continue;
            AdjList[a-1].push_back(make_pair(b-1,0));
        }
        cout << "Going to outptu num: " << endl;
        for(int i=0; i<V;i++)   if(dfs_num[i] == DFS_WHITE) tarjanSCC(i);
        cout << "init done" << endl;

        mmm = vi(V); 
        for(int i=0;i<Res.size();i++){
            mmm[Res[i][0]] = Res[i][0];
            for(int j=1;j<Res[i].size();j++){
                mmm[Res[i][j]] = Res[i][0];
            }
        }

        vl = vi(V,-1);
        for(int i=0;i<V;i++){
            a = mmm[i];
            for(int j=0;j<AdjList[i].size();j++){
                b = mmm[AdjList[i][j].first];
                if(a == b) continue;
                vl[b] = a;
            }
        }
        
        int count = 0;
        for(int i=0;i<Res.size();i++){
            if(vl[Res[i][0]] == -1) count++; 
        }

        printf("%d\n",count);
    }
    return 0;
}
