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

int tbl[1001], tblsize = 0;
int dif[1001];

int gcd(int a,int b){
    if(a < 0) a = -a;
    if(b < 0) b = -b;
    while(b != 0){
        int r = a%b;
        a = b; b = r;
    }
    return a;
}

int main(){
    int n,t;
    while(true){
        tblsize = 0;
        while(cin >> n,n){
            tbl[tblsize++] = n;
        }
        if(tblsize == 0)    break;

        for(int i=1;i<tblsize;i++){
            dif[i-1] = tbl[i] - tbl[i-1];
        }

        int m = dif[0];
        for(int i=1;i<tblsize-1;i++){
            m = gcd(m,dif[i]);
        }
        cout << m << endl;
    }
    return 0;
}
