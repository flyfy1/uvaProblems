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

char s[8];
bool visited[8];
bool appear[10];

bool testN(int n){
    sprintf(s,"%d",n);
    int l = strlen(s);
    memset(appear,0,sizeof appear); memset(visited,0,sizeof visited);
    int count = l;
    for(int i=0;i<l;i++)    if(appear[s[i] - '0'] == true)   return false; else appear[s[i] - '0'] = true;
    int c = 0;
    while(count){
        if(visited[c])  break;
        if(s[c] == '0') break;
        visited[c] = true; count--;
        n = s[c];n -= '0';
        c = (n+c) % l;
    }
    if(count || c != 0)   return false;
    return true;
}

vi table;

int main(){
    int N,CC = 1;
    for(int i=0;i<10000000;i++){
        if(testN(i))   table.push_back(i);
    }
    while(scanf("%d",&N),N){
        vi::iterator p = lower_bound(table.begin(),table.end(),N);
        printf("Case %d: %d\n",CC++,*p);
    }
    return 0;
}
