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
#define EPS 1e-7

using namespace std;

typedef pair<int,int>   ii;
typedef vector<int>     vi;
typedef vector<ii>      vii;
typedef vector<vi>     vvi;
typedef vector<vii>    vvii;
typedef map<int,int>    mii;

int cube[105];

int main(){
    double n;
    for(int i=0;i<105;i++){
        cube[i] = i*i*i;
    }

    while(cin >> n, n != 0){
        int p = lower_bound(cube,cube+101,n + EPS) - cube;
        
        if(cube[p] > n) p--;

        double dx = (n - cube[p]) / (3 * p * p);
        printf("%.4lf\n",p + dx);
    }

    return 0;
}
