#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
#include <cstring>
#include <cstdio>

using namespace std;

typedef pair<int, int> ii;

// direction -- 0 l, 1 u, 2 d, 3 r
// count -- and mark visited
int yy[] = {-1,0,1,0}, xx[] = {0,-1,0,1};
string mm[30];
int visited[30][30][5];    // the 5 means can be either of the 5 colors
int M,N;

int get_cost(int i,int d){
    int t = abs(i - d);
    if(t == 3)  t = 1;
    return t;
}

struct Cell{
    int c,d,x,y,o;  // cost, facing direction, x, y, color
    Cell(int cc,int dd,int xx,int yy,int oo){
        c = cc; d = dd; x = xx; y = yy; o = oo;
    }
    bool operator<(const struct Cell& b) const{
        return c > b.c;
    }
};

int main(){
    int count = 1; bool first = true;
    while(scanf("%d%d",&M,&N), M || N){
        if(first)   first = false;
        else putchar('\n');
        printf("Case #%d\n",count++);
        memset(visited,0,sizeof(visited));
        string t;
        getline(cin,t); // bypass the new line char
        for(int i=0;i<M;i++)    getline(cin,mm[i]);
        int sx = -1, sy = -1;
        for(int i=0;i<M;i++)    for(int j=0;j<N;j++) if(mm[i][j] == 'S'){sx = i; sy = j;break;}
        
        priority_queue<struct Cell> q;    // count, direction, first, second
        q.push(Cell(0,1,sx,sy,0));
        int cost = -1;
        while(!q.empty()){
            struct Cell e = q.top();    q.pop();
            if(visited[e.x][e.y][e.o] && e.c > visited[e.x][e.y][e.o])  continue;

            // for debugging
            // for(int i=0;i<M;i++){    for(int j=0;j<N;j++){ if(i != e.x || j != e.y) putchar(mm[i][j]); else putchar('X'); } putchar('\n');}
            // printf("x = %d, y = %d, o = %d, c = %d, d = %d\n",e.x,e.y,e.o,e.c,e.d);

            visited[e.x][e.y][e.o] = e.c;
            if(mm[e.x][e.y] == 'T' && e.o == 0){ cost = e.c; break;}
            for(int i=0;i<4;i++){
                int nx = e.x + xx[i], ny = e.y + yy[i];
                if(nx >= M || nx < 0 || ny >= N || ny < 0)  continue;
                if( mm[nx][ny] == '#')  continue;
                q.push(Cell(e.c + 1 + get_cost(i,e.d),i,nx,ny,(e.o + 1)%5 ));
            }
        }
        if(cost == -1)  printf("destination not reachable\n");
        else printf("minimum time = %d sec\n",cost);
    }
    return 0;
}

