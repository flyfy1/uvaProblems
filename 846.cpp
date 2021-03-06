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
    int a,b,M,k;
    int tc;
    cin >> tc;
    while(tc--){
        cin >> a >> b;
        M = b - a;
        k = sqrt(M);
        if(M == 0){
            cout << 0 << endl;
        } else if(M == k * k){
            cout << 2*k - 1 << endl;
        } else if(M <= k*(k+1)){
            cout << 2*k << endl;
        } else{
            cout << 2*k + 1 << endl;
        }
    }

    return 0;
}
