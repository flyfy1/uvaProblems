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

vvi mm;
int rn;
int parent[305];

int main(){
    string buf;
    int a,b,r;
    while(cin >> rn){
        mm = vvi(305);
        getline(cin,buf);
        for(int i=0;i<rn;i++){
            getline(cin,buf);
            for(int j=0;j<buf.size();j++){
                if(buf[j] == '-' || buf[j] == ',')  buf[j] = ' ';
            }
            istringstream in(buf);
            in >> a;
            while(in >> b){
                mm[a-1].push_back(b-1);
            }
        }

        cin >> r;
        printf("-----\n");
        for(int i=0;i<r;i++){
            cin >> a >> b;
            a--;b--;
            for(int i=0;i<305;i++)  parent[i] = -1;
            queue<ii> q;
            q.push(ii(a,0));
            while(!q.empty()){
                ii u = q.front(); q.pop();
                if(u.first == b)    break;
                for(int i=0;i<mm[u.first].size();i++){
                    int v = mm[u.first][i];
                    if(parent[v] != -1 || v == a) continue;
                    parent[v] = u.first;
                    q.push(ii(v,u.second++));
                }
            }
            if(parent[b] == -1){
                printf("connection impossible\n");
                continue;
            }
            stack<int> S;
            while(parent[b] != -1){
                S.push(b);
                b = parent[b];
            }
            printf("%d",a+1);
            while(!S.empty()){
                printf(" %d",1+ S.top());
                S.pop();
            }
            putchar('\n');
        }
    }
    return 0;
}
