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

int tbl[100];

int main(){
    int tc ;
    cin >> tc;
    for(int I = 1; I<=tc;I++){
        int n;
        cin >> n;
        for(int i=0;i<n;i++)    cin >> tbl[i];
        sort(tbl,tbl+n);
        printf("Case %d: %d\n",I,tbl[n/2]);
    }

    return 0;
}
