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
    int p,d,h;
    int x,y;
    int n;

    while(cin >> n){
        p =  sqrt((n-1)/3);
        if( (p+1)*p*3 < (n-1)) p++;
        int dif = n - 1 - p*(p-1)*3;
        d = (p == 0 ? 0 : (dif/p) % 6);
        h = (p == 0 ? 0 : (dif%p));
        switch(d){
            case 0:
                x = p-h; y = h; break;
            case 1:
                x = -h; y = p; break;
            case 2:
                x = -p; y = p-h; break;
            case 3:
                x = h-p; y = -h; break;
            case 4:
                x = h; y = -p; break;
            case 5:
                x = p; y = h-p; break;
            default: while(1);
        }
        printf("%d %d\n",x,y);
    }

    return 0;
}
