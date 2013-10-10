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

long long get_num(long long n){
    long long cc = 0;
    do{
        if(n%2) n = 3 * n + 1;
        else n = n / 2;

        cc++;
    }while(n != 1);
    return cc;
}

int main(){
    long long a,b,t;
    while(cin >> a >> b, a || b){
        if(a > b){
            t = a; a = b; b = t;
        }
        long long mc = 0, mv = 0;
        for(long long i=a;i<=b;i++){
            long long tc = get_num(i);
            if(mc < tc){
                mc = tc; mv = i;
            }
        }
        printf("Between %lld and %lld, %lld generates the longest sequence of %lld values.\n",a,b,mv,mc);
    }

    return 0;
}
