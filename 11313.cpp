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


int main(){
    int n,m;
    int TC;
    cin >> TC;
    while(TC--){
        cin >> n >> m;
        int cnt = 0;
        while(n >= m){
            cnt += n/m;
            n = n % m + n / m;
        }
        if(n == 1){
            printf("%d\n",cnt);
        } else{
            printf("cannot do this\n");
        }
    }

    return 0;
}
