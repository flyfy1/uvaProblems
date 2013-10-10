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

void articulationPointAndBridge(int u){
    dfs_low[u] = dfs_num[u] = dfsNumberCounter++;
    for(int j=0; j< (int) AdjList[u].size();j++){
        ii v = AdjList[u][j];
        if(dfs_num[v.first] == DFS_WHITE){
            dfs_parent[v.first] = u;
            if(u == dfsRoot) rootChildren++;

            articulationPointAndBridge(v.first);

            if(dfs_low[v.first] >= dfs_num[u])  articulation_vertex[u] = true;
            dfs_low[u] = min(dfs_low[u],dfs_low[v.first]);
        } else if(v.first != dfs_parent[u]) dfs_low[u] = min(dfs_low[u],dfs_num[v.first]);
    }
}

bool mm[105][105];

int main(){
    int CC = 1;
    bool first = true;
    while(cin >> V, V){
        if(first) first = false;
        else    putchar('\n');
        map<string,int> md;
        map<int,string> mb;
        memset(mm,0,sizeof mm);
        AdjList = vector<vii>(V);
        dfsNumberCounter = 0; dfs_num.assign(V,DFS_WHITE); dfs_low.assign(V,0);
        dfs_parent.assign(V,0); articulation_vertex.assign(V,0);

        string buf;
        for(int i=0;i<V;i++){
            cin >> buf;
            md[buf] = i;
            mb[i] = buf;
        }

        int M;cin >> M;
        string bufb;
        for(int i=0;i<M;i++){
            cin >> buf >> bufb;
            int na = md[buf], nb = md[bufb];
            mm[na][nb] = mm[nb][na] = true;
        }

        for(int i = 0; i<V;i++) for(int j = 0; j<V;j++) if(mm[i][j])    AdjList[i].push_back(make_pair(j,0));

        for(int i=0;i<V;i++){
            if( dfs_num[i] == DFS_WHITE){
                dfsRoot = i; rootChildren = 0;
                articulationPointAndBridge(i);
                articulation_vertex[dfsRoot] = (rootChildren > 1);
            }
        }

        vector<string> vo;
        for(int i=0;i<V;i++){
            if(articulation_vertex[i]) vo.push_back(mb[i]);
        }
        sort(vo.begin(),vo.end());
        printf("City map #%d: %d camera(s) found\n",CC++,(int)vo.size());
        for(int i=0;i<vo.size();i++){
            cout << vo[i] << endl;
        }
    }

    return 0;
}
