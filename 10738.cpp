// refer to http://www.cppblog.com/syhd142/articles/129050.html

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
#define VAL 1000001

using namespace std;

typedef pair<int,int>   ii;
typedef vector<int>     vi;
typedef vector<ii>      vii;
typedef vector<vi>     vvi;
typedef vector<vii>    vvii;
typedef map<int,int>    mii;

#define N 1000005

bool p[N];              // prime table for sieve
int m[N],               // the M table
    M[N],               // the m table
    prime[N/10], top;   // prime factors and its index/size
int factor[32];

vector<int> ft;

void sieve(){
    memset(p,1,sizeof(p));
    p[0] = p[1] = top = 0;
    m[1] = 1;
    // table of prime factors
    for(int i=0;i<1001;i++){
        if(p[i]){   // is prime
            m[i] = -1;  prime[top++] = i;
            for(int j = i*i; j<N;j+= i) p[j] = 0;
        }
    }

    // calculate m
    for(int i = 4; i<N;i++){
        if(p[i]){
            m[i] = -1;
            continue;
        }
        int t = i, k = 0, mk = 0;
        // factorize
        for(int j=0;prime[j] < t && j < top; j++){
            while(t % prime[j] == 0){
                factor[k++] = prime[j];
                t /= prime[j];
            }
        }
        if(t != 1)  factor[k++] = t;
        for(int j=1;j<k;j++){
            if(factor[j] == factor[j-1]){
                mk = 1;
                break;
            }
        }
        if(mk)  continue;
        if(k&1) m[i] = -1;
        else m[i] = 1;
    }
    for(int i=1;i<N;i++) M[i] = M[i-1] + m[i];
}

int main(){
    sieve();
    int n;
    while(scanf("%d",&n),n){
        printf("%8d%8d%8d\n",n,m[n],M[n]);
    }
    return 0;
}
