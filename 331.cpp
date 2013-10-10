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

vi s;

int cc = 0;
bool swaped = true;

void perf(){
    bool changed = false;
    for(int i=0;i<s.size()-1;i++){
        if(s[i] > s[i+1]){
            swaped = true;
            changed = true;
            int t = s[i]; s[i] = s[i+1]; s[i+1] = t;
            perf();
            t = s[i]; s[i] = s[i+1]; s[i+1] = t;
        }
    }
    if(!changed){
        cc++;
    }
}

int main(){
    int CC = 1;
    int n;

    while(scanf("%d",&n),n){
        s.clear();

        int t;
        for(int i=0;i<n;i++){
            cin >> t; s.push_back(t);
        }
        cc = 0;
        swaped = false;
        perf();
        printf("There are %d swap maps for input data set %d.\n",cc - (!swaped),CC++);
    }

    return 0;
}
