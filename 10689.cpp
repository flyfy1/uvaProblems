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

int tbl[15000];

int main(){
    int a,b,n,m,tc;
    cin >> tc;
    while(tc--){
        cin >> a >> b >> n >> m;
        tbl[0] = a; tbl[1] = b;
        for(int i=2;i<15000;i++){
            tbl[i] = tbl[i-1] + tbl[i-2];
            tbl[i] %= 10000;
        }
        int base = 1;
        for(int i=0;i<m;i++)    base *= 10;
        cout << tbl[n%15000] % base << endl;
    }
    return 0;
}
