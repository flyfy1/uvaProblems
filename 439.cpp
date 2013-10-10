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

int xx[] = {-1,1,2,2,1,-1,-2,-2}, yy[] = {-2,-2,-1,1,2,2,1,-1};

bool on_board(int x,int y){
    return (x >= 0 && y >= 0 && x <8 && y < 8);
}

int main(){
    string as,bs;
    while (cin >> as >> bs){
        int s = 8 * (as[0] - 'a') + as[1] - '1';
        int t = 8 * (bs[0] - 'a') + bs[1] - '1';
        queue<ii> q;
        q.push(ii(s,0));
        vector<bool> visited(64,false);
        int cost = -1;
        while(!q.empty()){
            ii u = q.front();q.pop();
            if(u.first == t){
                cost = u.second;
                break;
            }
            int x = u.first / 8, y = u.first % 8;
            for(int i=0;i<8;i++){
                int nx = x + xx[i], ny = y + yy[i];
                int ns = nx * 8 + ny;
                if(on_board(nx,ny) && !visited[ns]){
                    visited[ns] = true;
                    q.push(ii(ns,u.second + 1));
                }
            }
        }
        printf("To get from %s to %s takes %d knight moves.\n",as.c_str(), bs.c_str(),cost);
    }

    return 0;
}
