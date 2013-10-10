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
#define EPS 1e-8

using namespace std;

typedef pair<int,int>   ii;
typedef vector<int>     vi;
typedef vector<ii>      vii;
typedef vector<vi>     vvi;
typedef vector<vii>    vvii;
typedef map<int,int>    mii;

bool canPass(int c, double k1, double k2){
    return ( ceil(k1*c - EPS) <= floor(k2*c - EPS) );
}

int main(){
    double a,b,n;
    int c,d;
    double k1,k2;

    while(scanf("%lf%lf %lf",&a,&b,&n) == 3){
        k1 = b / (a + b*n); k2 = b / a;

        c = 1;
        while(!canPass(c,k1,k2)){
            c++;
        }
        d = ceil(k1 * c - EPS);

        printf("%d %d\n",c,d);
    }

    return 0;
}
