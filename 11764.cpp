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

int main(){
    int TC;
    cin >> TC;
    int CC = 1;
    while(TC--){
        int M;
        cin >> M;
        int former,t;
        int longj = 0,lowj = 0;
        for(int i=0;i<M;i++){
            cin >> t;
            if(i){
                if(former > t)  lowj++;
                else if(former < t) longj++;
            }
            former = t;
        }
        printf("Case %d: %d %d\n",CC++,longj,lowj);
    }

    return 0;
}
