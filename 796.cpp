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
typedef vector<ii>      vii;


int V;
int dfsNumberCounter=1, dfsRoot, rootChildren;
vector<int> dfs_num, dfs_low,dfs_parent;
vector<bool> articulation_vertex;

vector<vii> AdjList;
set<ii> bridges;

pair<int,int> getProperPair(int a,int b){
    return a < b ? make_pair(a,b) : make_pair(b,a);
}

void articulationPointAndBridge(int u){
    dfs_low[u] = dfs_num[u] = dfsNumberCounter++;
    for(int j=0; j< (int) AdjList[u].size();j++){
        ii v = AdjList[u][j];
        if(dfs_num[v.first] == DFS_WHITE){
            dfs_parent[v.first] = u;
            if(u == dfsRoot) rootChildren++;

            articulationPointAndBridge(v.first);

            if(dfs_low[v.first] > dfs_num[u])   bridges.insert(getProperPair(u,v.first));
            dfs_low[u] = min(dfs_low[u],dfs_low[v.first]);
        } else if(v.first != dfs_parent[u]) dfs_low[u] = min(dfs_low[u],dfs_num[v.first]);
    }
}

int main(){
    while(scanf("%d",&V) != EOF){
        dfsNumberCounter = 0; dfs_num.assign(V,DFS_WHITE); dfs_low.assign(V,0);
        dfs_parent.assign(V,0); articulation_vertex.assign(V,0);
        bridges.clear();

        vector< vector<bool> > mm(V);
        for(int i=0;i<V;i++)    mm[i] = vector<bool>(V,0);
        AdjList = vector<vii>(V);
        
        int u,n,t;
        for(int i=0;i<V;i++){
            scanf("%d (%d)",&u,&n);
            for(int j=0;j<n;j++){
                scanf("%d",&t);
                mm[u][t] = mm[t][u] = true;
            }
        }

        for(int i=0;i<V;i++)    for(int j=0;j<V;j++)    if(mm[i][j])    AdjList[i].push_back(make_pair(j,0));

        for(int i=0;i<V;i++){
            if( dfs_num[i] == DFS_WHITE){
                dfsRoot = i; rootChildren = 0;
                articulationPointAndBridge(i);
                articulation_vertex[dfsRoot] = (rootChildren > 1);
            }
        }

        printf("%d critical links\n",(int)bridges.size());
        for(set<ii>::iterator it = bridges.begin();it != bridges.end(); it++){
            printf("%d - %d\n",(*it).first,(*it).second);
        }
        putchar('\n');
    }

    return 0;
}
