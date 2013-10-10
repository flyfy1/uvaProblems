#include <iostream>
#include <cstdio>
#include <math.h>

using namespace std;

int main(){
    int m,n,res;
    while(cin >> m >> n, m != 0){
        if(m == 1 || n == 1){
            res = max(m,n);
        } else if(m == 2 || n == 2){
            int c = max(m,n);
            res = (2 * (c%4 - (c%4 == 3) ) + c/4 * 4 );
        } else{
            res = m/2 * n + (m&1) * (n/2 + (n&1));
        }
        printf("%d knight%s may be placed on a %d row %d column board.\n",
                res, "s",m,n);
    }
    return 0;
}
