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



int main(){
    int N,r,nd;
    int x,y;
    while(cin >> N, N){
        r = sqrt(N);
        if(r * r == N)  r--;
        nd = N - r*r;
        if(r & 1){
            if(nd > r){ x = r + 1; y = 2 * r + 2 - nd;}
            else{ x = nd; y = r + 1;}
        } else{
            if(nd > r){ x = 2 * r + 2 - nd; y = r + 1;}
            else{ x = r + 1; y = nd;}
        }
        printf("%d %d\n",x,y);
    }

    return 0;
}
