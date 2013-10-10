#include <iostream>
#include <cstdio>

#define VAL 1000001

using namespace std;

long long tbl[VAL];

int main(){
    tbl[3] = 0;
    for(int i = 4;i<VAL;i++){
        long long k = i/2;
        // tbl[i] = ((long long)(i-2)) * (i-3) / 2 - tbl[i-1];
        tbl[i] = tbl[i-1] + k * (k + (i&1)) - i + 1;
    }
    int n;
    while(scanf("%d",&n), n >= 3){
        printf("%llu\n",tbl[n]);
    }

    return 0;
}
