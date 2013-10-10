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

#define cube(x) (x*x*x)

using namespace std;

typedef pair<int,int>   ii;
typedef vector<int>     vi;
typedef vector<ii>      vii;

int main(){
    for(int i=6;i<=200;i++)
        for(int j=2;j<i;j++)
            for(int k=j;k<=i;k++)
                for(int l=k;l<=i;l++){
                    if(cube(i) == cube(j) + cube(k) + cube(l)){
                        printf("Cube = %d, Triple = (%d,%d,%d)\n",i,j,k,l);
                    }
                }
    
    return 0;
}
