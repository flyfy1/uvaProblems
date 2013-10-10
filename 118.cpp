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

int xx[] = {0,1,0,-1};
int yy[] = {1,0,-1,0};

bool mm[55][55];
int X,Y;
int rx,ry;
int rdir;

char dirChar[] = {'N','E','S','W'};

int getDir(char c){
    switch(c){
        case 'N': return 0;
        case 'E': return 1;
        case 'S': return 2;
        case 'W': return 3;
        default:  return 1000; // hope to get runtime error
    }
}

char getDirChar(int dir){
}

bool move(){
    int nx = rx + xx[rdir], ny = ry + yy[rdir];
    if(nx < 0 || ny < 0 || nx > X || ny > Y)    return false;
    rx = nx; ry = ny;
    return true;
}

int main(){
    string buf;
    memset(mm,0,sizeof mm);
    cin >> X >> Y;
    while( cin >> rx >> ry >> buf){
        rdir = getDir(buf[0]);
        cin >> buf;
        bool lost = false;
        for(int i=0;i<buf.size() && !lost;i++){
            switch(buf[i]){
            case 'R':
                rdir = (rdir + 1) % 4;  break;
            case 'L':
                rdir = (rdir - 1 + 4) % 4;  break;
            case 'F':
                if(!move()){
                   if(mm[rx][ry])  continue;
                   mm[rx][ry] = true;
                   lost = true;
                   break;
                }
            }
        }
        printf("%d %d %c%s\n",rx,ry,dirChar[rdir],(lost)?" LOST":"");
    }

    return 0;
}
