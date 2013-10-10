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
typedef vector<int>     vi;
typedef vector<ii>      vii;

int hh[10005];

int main(){
    int x,h,y;
    memset(hh,0,sizeof(hh));

    while(scanf("%d%d%d",&x,&h,&y) != EOF){
        for(int i=x;i<=y;i++)   if(h > hh[i])   hh[i] = h;
    }

    int s = 0;
    while(hh[s] == 0) s++;
    printf("%d %d",s,hh[s]);
    int ph = hh[s]; 

    for(int i=s;i<10005;i++){
        if(hh[i] == ph) continue;
        else if(ph > hh[i]){
            printf(" %d %d",i-1,hh[i]);
            ph = hh[i];
        } else{
            printf(" %d %d",i,hh[i]);
            ph = hh[i];
        }
    }
    putchar('\n');

    return 0;
}
