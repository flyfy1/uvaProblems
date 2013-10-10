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

int TC;
char buf[12];
bool visited[11];

bool isUnique(long long n){
    if(n < 0)   return false;
    sprintf(buf,"%lld",n);
    memset(visited,0,sizeof visited);
    int l = strlen(buf);
    // cout << buf << endl;
    for(int i=0;i<l;i++){
        if(visited[buf[i] - '0']){
            // cout << "returning false, i=" << buf[i] - '0' << endl;
            return false;
        }
        visited[buf[i] - '0'] = true;
    }
    return true;
}

int main(){
    cin >> TC;
    bool first = true;
    while(TC--){
        long long n;
        cin >> n;
        if(first) first = false; else putchar('\n');
        for(int i = 1; i <= 10000000000/n;i++){
            if(isUnique(i) && isUnique(n*i)){
                printf("%lld / %d = %lld\n",n*i,i,n);
            }
           // cout << " i = " << i << endl;
        }
        // cout << "done " << endl;
    }

    return 0;
}
