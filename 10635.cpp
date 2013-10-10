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


int n,p,q;

int main(){
    int CC = 1,TC;
    cin >> TC;
    while(TC--){
        cin >> n >> p >> q;
        vi a(p+1),b(q+1);
        for(int i=0;i<=p;i++){
            cin >> a[i];
        }
        for(int i=0;i<=q;i++){
            cin >> b[i];
        }
    }

    return 0;
}
