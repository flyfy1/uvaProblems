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

vi v;
vector<bool> visited;
int N;
vi S;
void backTrack(int s){
    if(S.size() == 5){
        for(int i=0;i<S.size();i++) printf("%d ",v[S[i]]);
        printf("%d\n",v[s]);
        return;
    }
    //if(S.size() + (N-s) < N)    return;
    S.push_back(s);
    visited[s] = true;
    for(int i=s+1;i<N;i++){
        if(!visited[i]) backTrack(i);
    }
    visited[s] = false;
    S.pop_back();
}

int main(){
    bool first = true;
    while(cin >> N,N){
        if(first) first = false; else putchar('\n');
        v = vi(N);
        for(int i=0;i<N;i++)    cin >> v[i];
        for(int i=0;i<N;i++){
            visited.assign(N,false);
            backTrack(i);
        }
    }

    return 0;
}
