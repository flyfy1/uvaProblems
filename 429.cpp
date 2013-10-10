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

bool mm[202][202];

bool diffBy1(string a, string b){
    if(a.size() != b.size())    return false;
    int difNum = 0;
    for(int i=0;i<a.size();i++){
        if(a[i] != b[i] && ++difNum > 1){
            return false;
        }
    }
    return difNum == 1;
}

int main(){
    int TC;
    cin >> TC;
    string as,bs;
    bool first = true;

    while(TC--){
        vector<string> ss;
        map<string,int> mp;
        while(cin >> as, as[0] != '*'){
            mp[as] = ss.size();
            ss.push_back(as);
        }
        string buf;

        if(first)   first = false;
        else    cout << endl;

        // then build the dic arr
        memset(mm,0,sizeof(mm));
        for(int i=0;i<ss.size();i++){
            for(int j=i+1;j<ss.size();j++){
                if(diffBy1(ss[i],ss[j])){
                    int a = mp[ss[i]], b = mp[ss[j]];
                    mm[a][b] = mm[b][a] = 1;
                }
            }
        }
        
        getline(cin,buf);
        while(getline(cin,buf) && buf != ""){
            istringstream in(buf);
            in >> as >> bs;
            int s = mp[as], d = mp[bs];
            // perform bfs
            queue<ii> q;
            q.push(ii(s,0));
            vector<bool> visited(ss.size(),false);
            int cost = -1;
            while(!q.empty()){
                ii u = q.front(); q.pop();
                if(u.first == d){
                    cost = u.second;
                    break;
                }
                for(int i=0;i<ss.size();i++){
                    if(mm[u.first][i] && !visited[i]){
                        visited[i] = true;
                        q.push(ii(i,u.second + 1));
                    }
                }
            }
            cout << as << " " << bs << " " << cost << endl;
        }
    }

    return 0;
}
