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

int R[1000];
int B[100];

int main(){
    long long n;
    int CC = 1;
    int TC;
    cin >> TC;
    while(TC--){
        cin >> n;
        memset(B,0,sizeof(B));
        memset(R,0,sizeof(R));
        bool minus = 0;
        if( n < 0){
            minus = 1;
            n = -n;
        }
        long long base = 1;
        int cnt = 0;
        while(base < n){
            base *= 2;
            cnt++;
        }
        int mr = 0;
        if(minus){
            n = base - n;
            R[cnt]++; mr = cnt;
            if((cnt&1) == 0){
                R[cnt+1]++;
                mr = cnt+1;
            }
        }
        int mb = cnt - (base != n);
        while(n > 0){
            while(base > n){
                base /= 2; cnt--;
            }
            n -= base; B[cnt]++;
        }

        int former1 = 0;
        int i = 0;
        for(i=0;i<=mb || former1;i++){
            if(i <= mb && B[i]){
                R[i]++;
                if(i&1) R[i+1]++;
            }
            while(R[i] > 1 && R[i+1] > 0){
                R[i] -= 2; R[i+1] -= 1;
            }
            
            if(R[i] > 1){
                int pt = R[i] / 2;
                R[i] &= 1;
                R[i+1] += pt;
                R[i+2] += pt;
                former1 = 2;
            } else if(R[i]){
                former1 = 1;
            } else{
                former1--;
            }
        }
        mr = max(i - !former1 - 1,mr);
        printf("Case #%d: ",CC++);
        bool output1 = false;
        for(i = 999;i>=0;i--){
            if(!output1 && !R[i])   continue;
            else output1 = 1;
            if(R[i])    putchar('1');
            else    putchar('0');
        }
        putchar('\n');
    }

    return 0;
}
