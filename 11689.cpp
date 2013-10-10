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
    int e,f,c;
    int res,n;
    int TC;
    cin >> TC;
    while(TC--){
        cin >> e >> f >> c;

        n = e + f;
        res = 0;
        while(n >= c){
            res += n/c;
            n = n/c + n % c;
        }
        cout << res << endl;
    }

    return 0;
}
