// I think i'd better not wasting my time on this problem... don't understand why it doesn't work

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
#define VAL 500000

using namespace std;

typedef pair<int,int>   ii;
typedef vector<int>     vi;
typedef vector<ii>      vii;
typedef vector<vi>     vvi;
typedef vector<vii>    vvii;
typedef map<int,int>    mii;

bool pm[VAL];
int ft[100000];
int ft_size = 0;

void factorize(int n,mii& m){
    int idx = 0;
    while(n > 1 && idx < ft_size){
        if(n % ft[idx] == 0){
            n /= ft[idx];
            m[ft[idx]]++;
        } else{
            idx++;
        }
    }
}

int main(){
    memset(pm,1,sizeof pm);

    for(long long i=2;i<VAL;i++){
        if(!pm[i]) continue;
        ft[ft_size++] = i;
        for(long long j = i*i;j<VAL;j+=i){
            pm[j] = false;
        }
    }

    int n,m;
    while(cin >> n >> m){
        mii mt;
        factorize(m,mt);
        int divisible = true;
        if(m == 0) divisible = false;
        for(mii::iterator it = mt.begin(); it != mt.end() && divisible; it++){
            int sum = n / it->first; int r = sum;
            while(r > 0){
                r /= it->first;
                sum += r;
            }
            if(sum < it->second){
                divisible = false; break;
            }
        }

        printf("%d %s %d!\n",m,divisible?"divides":"does not divide",n);
    }

    return 0;
}
