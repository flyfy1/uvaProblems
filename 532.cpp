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

bool visited[35][35][35];

struct P{
    int x,y,z;
    P(int xx, int yy, int zz){
        x = xx, y = yy, z = zz;
    }
    P(){}

    const bool operator==(const P& b) const{
        return x == b.x && y == b.y && z == b.z;
    }
};

vector<vector<string> > mmm;
int L,R,C;

bool isInRagne(P p){
    return p.x >= 0 && p.y >= 0 && p.z >= 0 
        && p.x < L && p.y < R && p.z < C;
}

bool isVisitable(P p){
    if(visited[p.x][p.y][p.z])  return false;
    char c=  mmm[p.x][p.y][p.z];
    return c == 'S' || c == '.' || c =='E';
}

int xx[] = {0,1,0,-1,0,0};
int yy[] = {-1,0,1,0,0,0};
int zz[] = {0,0,0,0,-1,1};

int main(){
    while( cin >> L >> R >> C, L || R || C){
        mmm.clear();
        for(int i=0;i<L;i++){
            vector<string> mm(R);
            for(int j=0;j<R;j++){
                cin >> mm[j];
            }
            mmm.push_back(mm);
        }

        // find the s first
        P s,e;
        for(int i=0;i<L;i++){
            for(int j=0;j<R;j++){
                for(int k=0;k<C;k++){
                    char c = mmm[i][j][k];
                    if(c == 'S'){
                        s = P(i,j,k);
                    } else if(c == 'E'){
                        e = P(i,j,k);
                    }
                }
            }
        }

        memset(visited,0,sizeof(visited));
        queue<pair<P,int> > q;
        q.push(make_pair(s,0));
        int cost = -1;
        while(!q.empty()){
            pair<P,int> u = q.front(); q.pop();
            for(int i=0;i<6;i++){
                P up = u.first;
                if(up == e){
                    cost = u.second;
                    break;
                }
                P v = P(up.x + xx[i],up.y+yy[i], up.z + zz[i]);
                if(isInRagne(v) && isVisitable(v) ){
                    visited[v.x][v.y][v.z] = true;
                    q.push(make_pair(v,u.second + 1));
                }
            }
        }
        if(cost == -1)  printf("Trapped!\n");
        else printf("Escaped in %d minute(s).\n",cost);
    }
    return 0;
}
