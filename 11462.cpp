#include <iostream>
#include <vector>
#include <string>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int main(){
    char a[2000000];
    int n,i;

    while(scanf("%d",&n),n){
        for(i=0;i<n;i++){
            scanf("%d",&a[i]);
        }
        sort(a,a+n);

        for(i=0;i<n;i++){
            if(i!=0)    putchar(' ');
            printf("%d",a[i]);
        }
        putchar('\n');
    }
}
