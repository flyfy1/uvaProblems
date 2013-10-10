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
#include <cmath>

using namespace std;

typedef pair<int,int>   ii;
typedef vector<int>     vi;
typedef vector<ii>      vii;
typedef vector<vi>     vvi;
typedef vector<vii>    vvii;
typedef map<int,int>    mii;

long long s,x,y,dx,dy;

bool in_white(){
    if(x%s == 0 || y%s == 0)    return false;
    return (x/s + y/s)&1;
}

bool can_get_slution(){
    if(in_white())  return true;
    if(x%s == 0 && dx%s == 0)   return false;
    if(y%s == 0 && dy%s == 0)   return false;
    return !(dx%s == 0 && dy%s == 0);
}

int main(){
    while(cin >> s >> x >> y >> dx >> dy, s | x | y | dx | dy){
        if(!can_get_slution()){
            printf("The flea cannot escape from black squares.\n");
            continue;
        }
        int cnt = 0;
        while(!in_white() && cnt < 1200){
            x += dx; y += dy;
            cnt++;
        }
        if(cnt == 1200){
            printf("The flea cannot escape from black squares.\n");
        } else{
            printf("After %d jumps the flea lands at (%lld, %lld).\n",cnt,x,y);
        }
    }

    return 0;
}
