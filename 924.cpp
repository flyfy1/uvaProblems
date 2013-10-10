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

bool visited[2505];

int main(){
    int E,TC;
    cin >> E;
    vvi mm(E);
    int a,b;
    for(int i=0;i<E;i++){
        cin >> a;
        for(int j=0;j<a;j++){
            cin >> b;
            mm[i].push_back(b);
        }
    }
    
    cin >> TC;
    while(TC--){
        memset(visited,0,sizeof visited);
        int s,mmax = 0,d = -1,pval = 0;
        queue<ii> q;
        int cpeople = 0;
        cin >> s;
        q.push(ii(s,0));
        visited[s] = 1;
        while(!q.empty()){
            ii u = q.front(); q.pop();
            int up = u.first;
            if(u.second != pval){
                if(mmax < cpeople){
                    mmax = cpeople; d = pval;
                }
                pval = u.second;
                cpeople = 0;
            }
            for(int i=0;i<mm[up].size();i++){
                int v = mm[up][i];
                if(!visited[v]){
                    visited[v] = true;
                    q.push(ii(v,u.second + 1));
                    cpeople++;
                }
            }
        }
        if(d == -1) cout << 0 << endl;
        else cout << mmax << " " << d+1 << endl;
    }
    
    return 0;
}
