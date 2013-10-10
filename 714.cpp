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

long long p[505];
int k,m;

bool testOK(long long n){
    int tk = 0;
    int idx = m-1;
    long long s = n;
    while(tk < k && idx > 0){
        while(idx>0){
            s -= p[idx];
            if(s < 0){ s = n; break;}
            idx--;
            if(s == 0)  break;
        }
        if(idx) tk++;
    }
    if(tk == k) return true;
    return false;
}

int main(){
    int TC;
    scanf("%d",&TC);
    while(TC--){
        scanf("%d%d",&m,&k);
        for(int i=0;i<m;i++)    scanf("%lld",p+i);

        long long gh = 5000000000ll, gl = 1;
        long long res= -1;
        while(gh > gl){
            long long gm = (gh + gl) / 2;
            bool tc = testOK(gm),tb = testOK(gm-1);
            if(tc && tb){
                gh = gm+1;
            } else if(!tc && !tb){
                gl = gm+1;
            } else{
                res = gm; break;
            }
        }
    }

    return 0;
}
