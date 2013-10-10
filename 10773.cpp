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



int main(){
    int TC;
    cin >> TC;
    for(int I = 1; I <= TC; I++){
        int u,v,d;
        cin >> d >> v >> u;
        printf("Case %d: ",I); 
        if(u <= v || v == 0) cout << "can't determine" << endl;
        else{
            double res = ((double) d)/ sqrt(u*u - v*v) - (((double) d)/u);
            printf("%.3lf\n",res);
        }
    }

    return 0;
}
