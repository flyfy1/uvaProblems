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
typedef vector<vi>     vvi;
typedef vector<ii>      vii;
typedef vector<vii>    vvii;

vvi el;
int u,v;
int N;
bool mm[105];

int main(){
    while(cin >> N, N){
        el = vvi(N);
        while(cin >> u,u){
            while(true){
                cin >> v;
                if(v == 0)  break;
                el[u-1].push_back(v-1);
            }
        }
        cin >> u;
        for(int i=0;i<u;i++){
            cin >> v;
            memset(mm,0,sizeof mm);
            queue<int> q;
            q.push(v-1);
            bool first = true;
            while(!q.empty()){
                v = q.front();
                q.pop();
                if(mm[v])   continue;
                if(!first) mm[v] = true;
                else    first = false;
                for(int j=0;j<el[v].size();j++) q.push(el[v][j]);
            }
            int tt = 0;
            for(int j=0;j<N;j++)    if(!mm[j])  tt++;
            printf("%d",tt);
            for(int j=0;j<N;j++)    if(!mm[j])  printf(" %d",j+1);
            putchar('\n');
        }
    }
    return 0;
}
