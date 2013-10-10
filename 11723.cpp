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

using namespace std;

typedef pair<int,int>   ii;
typedef vector<int>     vi;
typedef vector<ii>      vii;
typedef vector<vi>     vvi;
typedef vector<vii>    vvii;



int main(){
    int R,N, TC = 1;
    while(cin >> R >> N, R | N){
        int res = R / N - (R%N == 0);
        printf("Case %d: ",TC++);
        if(res > 26)    printf("impossible\n");
        else printf("%d\n",res);
    }

    return 0;
}
