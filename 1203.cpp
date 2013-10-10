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

char buf[100];

struct Cell{
    int num;
    int t;
    Cell(int nn,int tt){ num = nn; t = tt;}
    const bool operator<(const Cell& c) const{
        if( t != c.t)   return t > c.t;
        else            return num > c.num;
    }
};

int main(){
    int K;
    priority_queue<Cell > q;
    int n,t;
    vector<int> num,period;

    while(fgets(buf,100,stdin),buf[0] != '#'){
        sscanf(buf,"%*s%d%d",&n,&t);
        num.push_back(n); period.push_back(t);
    }
    scanf("%d",&K);
    for(int i=1;i<=K;i++){
        for(int j = 0;j<num.size();j++){
            q.push(Cell(num[j],i * period[j]));
        }
    }
    while(K--){
        printf("%d\n",q.top().num);
        q.pop();
    }
    return 0;
}
