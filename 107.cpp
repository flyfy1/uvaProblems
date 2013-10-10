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

#define EPS 1e-6


int main(){
    long long H,K;
    long long n,m;

    while(cin >> H >> K, H || K){
        if(K == 1){
            n = 1; m = floor(log(H)/log(2) + EPS);
            double rb = (pow(2,(double)m+1) - 1);
            printf("%lld %.0lf\n",m,rb);
            continue;
        }
        
        double HoK = ((double)H) / K;
        m = -1;
        for(int i=1;i<64;i++){
            double tres = 1 / (pow(HoK,1.0/i) - 1);
            n = floor(tres + EPS);
            if(abs(tres - n) < EPS){
                m = i; break;
            }
        }

        // use for debugging
        if(m < 0)   while(1);
        
        double q = ((double)n)/(n+1);
        double ra = (pow(n,(double)m)-1)/(n-1);
        double rb = (pow(q,(double)m+1)-1)/(q-1);
        printf("%.0lf %.0lf\n",ra,H*rb);
    }

    return 0;
}
