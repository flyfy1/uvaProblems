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

using namespace std;

typedef pair<int,int>   ii;

int SX,SY;
string m[21];
int R,C;
char CL;

int xx[] = {-1,0,0,1}, yy[] = {0,1,-1,0};

int fillCount(int x,int y){
    if(x < 0 || y < 0 || x >= R || y >= C)  return 0;
    if(m[x][y] != CL)  return 0;
    m[x][y] = CL+1;
    int sum = 1;
    for(int i=0;i<4;i++)    sum += fillCount(x + xx[i],(C + y + yy[i])%C);
    return sum;
}

int main(){
    string buf;
    while(scanf("%d%d",&R,&C) != EOF){
        getline(cin,buf);
        for(int i=0;i<R;i++){
            getline(cin,buf);
            m[i] = buf;
        }
        scanf("%d%d",&SX,&SY);
        CL = m[SX][SY];
        fillCount(SX,SY);
        int res = 0;
        for(int i=0;i<R;i++){
            for(int j=0;j<C;j++){
                res = max(res,fillCount(i,j));
            }
        }
        cout << res << endl;
    }
    return 0;
}
