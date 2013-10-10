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
#define UP 10000

using namespace std;

typedef pair<int,int>   ii;
typedef vector<int>     vi;
typedef vector<ii>      vii;
typedef vector<vi>     vvi;
typedef vector<vii>    vvii;

vi ft;
vector<bool> sei(UP,0);

void factorize(int n,map<int,int> &mm){
    int hn = sqrt(n) + 1,idx = 0;
    while(idx < UP && ft[idx] < hn && n > 1){
        int m = ft[idx];
        if(n % m == 0){
            n /= m;
            if(mm.count(m)){
                mm[m] = mm[m]+1;
            } else{
                mm[m] = 1;
            }
        } else  idx++;
    }
    if(n > 1)   mm[n] = 1;
}

int main(){
    for(int i=2;i<UP;i++){
        if(!sei[i]){
            ft.push_back(i);
            for(int j=2;i*j < UP;j++){
                sei[i*j] = 1;
            }
        }
    }
    sei.clear();

    int TC,a,c;
    scanf("%d",&TC);
    while(TC--){
        scanf("%d %d",&a,&c);
        map<int,int> fa,fc;
        factorize(a,fa);
        factorize(c,fc);

        bool hasSolution = true;
        for(map<int,int>::iterator ia = fa.begin(); ia != fa.end();ia++){
            if(fc[ia->first] < ia->second){
                hasSolution = false;    break;
            }
            if(fc[ia->first] == ia->second) fc[ia->first] = 0;
        }
        

        if(!hasSolution){
            printf("NO SOLUTION\n");
            continue;
        }
        int b = 1;
        for(map<int,int>::iterator ic = fc.begin(); ic != fc.end(); ic++){
            for(int i=0;i < ic->second;i++)  b *= ic->first;
        }
        printf("%d\n",b);
    }

    return 0;
}
