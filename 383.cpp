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

int main(){
    int TC;
    cin >> TC;
    int CC = 1;
    printf("SHIPPING ROUTES OUTPUT\n");
    while(TC--){
        printf("\nDATA SET  %d\n\n",CC++);
        memset(mm,0,sizeof mm); 
        nc = 0;
        string as,bs;
        int M,N,P;
        cin >> M >> N >> P;
        map<string,int> mp;
        for(int i=0;i<M;i++){
            cin >> as;
            mp[as] = nc++;
        }
        for(int i=0;i<N;i++){
            cin >> as >> bs;
            int a = mp[as], b = mp[bs];
            mm[a][b] = mm[b][a] = 1;
        }
        int size;
        for(int i=0;i<P;i++){
            cin >> size >> as >> bs;
            // perform the bfs
            int s = mp[as], d = mp[bs];
            queue<ii> q;
            q.push(ii(s,0));
            vector<bool> visited(nc,false);
            visited[s] = true;
            long long val = -1;
            while(!q.empty()){
                ii u = q.front(); q.pop();
                if(u.first == d)    val = u.second;
                for(int i=0;i<nc;i++){
                    if(mm[u.first][i] && !visited[i]){
                        q.push(ii(i,u.second+1));
                        visited[i] = true;
                    }
                }
            }
            if(val == -1)   printf("NO SHIPMENT POSSIBLE\n");
            else    printf("$%lld\n",val * size * 100);
        }
    }
    printf("\nEND OF OUTPUT\n");
    return 0;
}
