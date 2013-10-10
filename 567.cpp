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

int mm[25][25];
bool visited[25];

int main(){
    int TC = 1;
    while(true){
        int a,b,r;
        memset(mm,0,sizeof(mm));
        for(int i=0;i<19;i++){
            if(!(cin >> a))    goto end;
            while(a--){
                cin >> b; b--;
                mm[i][b] = mm[b][i] = 1;
            }
        }
        printf("Test Set #%d\n",TC++);
        cin >> r;
        while(r--){
            cin >> a >> b;
            memset(visited,0,sizeof visited);
            queue<ii> q;
            q.push(ii(a-1,0));
            visited[a-1] = 1;
            int cost = -1;
            while(!q.empty()){
                ii u = q.front(); q.pop();
                if(u.first == b-1){
                    cost = u.second; break;
                }
                for(int i=0;i<20;i++){
                    if(mm[u.first][i] && !visited[i]){
                        visited[i] = true;
                        q.push(ii(i,u.second+1));
                    }
                }
            }
            printf("%2d to %2d: %d\n",a,b,cost);
        }
        putchar('\n');
    }
    end:
    return 0;
}
