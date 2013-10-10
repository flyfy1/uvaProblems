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

using namespace std;

typedef pair<int,int>   ii;
typedef vector<int>     vi;
typedef vector<ii>      vii;
typedef vector<vi>     vvi;
typedef vector<vii>    vvii;

bool mm[35][35];
int nc;

void addMap(map<int,int> &mp,int a,int b){
    if(mp.count(a)) a=mp[a];
    else{ mp[a] = nc++; a = mp[a];}
    if(mp.count(b)) b=mp[b];
    else{ mp[b] = nc++; b = mp[b];}
    mm[a][b] = mm[b][a] = 1;
}

int main(){
    int NC;
    int TC = 1;
    
    while(cin >> NC, NC){
        int a,b;
        nc = 0;
        memset(mm,0,sizeof(mm));
        map<int,int> mp;
        while(NC--){
            cin >> a >> b;
            addMap(mp,a,b);
        }
        
        // then perform BFS
        while(cin >> a >> b, a || b){
            vector<bool> visited(nc,false);
            queue<ii> q;
            q.push(ii(mp[a],b)); visited[mp[a]] = true;
            while(!q.empty()){
                ii u = q.front(); q.pop();
                if(u.second == 0)   continue;
                for(int i =0;i<nc;i++){
                    if(mm[u.first][i] && !visited[i]){
                        visited[i] = true; q.push(ii(i,u.second -1));
                    }
                }
            }
            int cnt = 0;
            for(int i=0;i<nc;i++)   if(!visited[i]) cnt++;
            printf("Case %d: %d nodes not reachable from node %d with TTL = %d.\n",TC++,cnt,a,b);
        }
    }


    return 0;
}
