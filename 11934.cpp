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
    int a,b,c,d,L,s;
    while(cin >> a >> b >> c >> d >> L, a || b || c || d || L){
        int cnt = 0;
        for(int i=0;i<=L;i++){
            if( (a * i * i + b * i + c) % d == 0)   cnt++;
        }
        cout << cnt << endl;
    }

    return 0;
}
