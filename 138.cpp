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
    long long p,q;
    for(q = 8; q <= 65918161; q++){
        long long s = q * (q+1) / 2;
        p = sqrt(s);
        if(p*p == s){
            printf("%10lld%10lld\n",p,q);
        }
    }

    return 0;
}
