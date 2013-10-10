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


int main(){
    while(1){
        int co;
        bool st = false;
        for(int i=8;i>=0;i--){
            if(!(cin >> co))    return 0;
            if(co == 0) continue;

            // +/-
            if(!st){
                if(co < 0){
                    putchar('-');
                }
                st = 1;
            } else{
                printf(" %c ",co > 0?'+':'-');
            }

            // coefficient
            if(co < 0)  co = -co;
            if(co == 1 && i != 0){
                // do nothing
            } 
            else{
                printf("%d",co);
            }
            if(i == 0)  continue;

            // x term
            putchar('x');
            if(i > 1)   printf("^%d",i);
        }
        if(!st) printf("0");
        putchar('\n');
    }

    return 0;
}
