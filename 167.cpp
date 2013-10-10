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

int mm[8][8];

int maxv;

vii v;

bool collidePoints(ii a,ii b){
    if(a.first == b.first)  return true;
    if(a.second == b.second)  return true;
    if(abs(a.first - b.first) == abs(a.second - b.second))  return true;
    return false;
}

bool collideAt(int x,int y){
    for(int i=0;i<v.size();i++){
        if(collidePoints(v[i],ii(x,y))) return true;
    }
    return false;
}

void cal(int coln){
    if(v.size() == 8){
        int sum = 0;
        for(int i=0;i<8;i++){
            sum += mm[v[i].first][v[i].second];
        }
        maxv = max(sum,maxv);
        return;
    }

    // find the proper location of queen on current row
    for(int i=0;i<8;i++){
        if(!collideAt(coln,i)){
            v.push_back(ii(coln,i));
            cal(coln+1);
            v.pop_back();
        }
    }
}

int main(){
    int tc,t;
    cin >> tc;
    while(tc--){
        for(int i=0;i<8;i++){
            for(int j=0;j<8;j++){
                cin >> mm[i][j];
            }
        }
        maxv = 0;v.clear();
        cal(0);
        printf("%5d\n",maxv);
    }

    return 0;
}
