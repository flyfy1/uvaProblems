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
vector<int> dfs_num, dfs_low,S,visited;

vector<vii> AdjList;

void tarjanSCC(int u){
    dfs_low[u] = dfs_num[u] = dfsNumberCounter++;
    S.push_back(u);
    visited[u] = 1;
    for(int j = 0; j < (int) AdjList[u].size(); j++){
        ii v = AdjList[u][j];
        if(dfs_num[v.first] == DFS_WHITE)   tarjanSCC(v.first);
        if(visited[v.first])    dfs_low[u] = min(dfs_low[u],dfs_low[v.first]);
    }
    if(dfs_low[u] == dfs_num[u]){
        printf("SCC %d:", ++numSCC);
        while(1){
            int v = S.back(); S.pop_back(); visited[v] = 0;
            printf(" %d",v);
            if( u == v) break;
        }
        printf("\n");
    }
}

int main(){

    dfs_num.assign(V,DFS_WHITE); dfs_low.assign(V,0); visited.assign(V,0);
    dfsNumberCounter = numSCC = 0;
    for(int i=0; i<V;i++)   if(dfs_num[i] == DFS_WHITE) tarjanSCC(i);

    return 0;
}
