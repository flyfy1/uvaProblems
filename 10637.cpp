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

int gcd(int a, int b){
    int r;
    while(b > 0){
        r = a%b;
        a = b;
        b = r;
    }
    return a;
}

int S,T;
vector<int> v;

bool coprime(int a){
    for(int i=0;i<v.size();i++){
        if(gcd(v[i],a) != 1)    return false;
    }
    return true;
}

void generate(int s,int l){
    if(s * (T - v.size()) > l || l < 0)   return;
    if(v.size() == T){
        if(l != 0)  return;
        printf("%d",v[0]);
        for(int i=1;i<v.size();i++){
            printf(" %d",v[i]);
        }
        putchar('\n');
        return;
    }
    
    for(int i=s;i<=l;i++){
        if(coprime(i)){
            v.push_back(i);
            generate(i,l-i);
            v.pop_back();
        }
    }
    return;
}

int main(){
    int TC,CC=1;
    scanf("%d",&TC);
    while(TC--){
        scanf("%d%d",&S,&T);
        v.clear();
        printf("Case %d:\n",CC++);
        generate(1,S);
    }

    return 0;
}
