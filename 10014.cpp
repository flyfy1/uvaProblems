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

int n;
double arrc[3005];
double a0,an1;

int main(){
    int TC;
    cin >> TC;
    bool first = true;
    while(TC--){
        cin >> n;
        cin >> a0 >> an1;
        for(int i=0;i<n;i++){
            cin >> arrc[i+1];
        }
        
        double res = 0;
        if(n == 0){
            res = an1;
        } else if(n == 1){
            res = (a0 + an1) / 2 - arrc[1];
        } else{
            double csum = 0;
            for(int i=0;i<n;i++){
                csum += 2*(n-i)*arrc[i+1];
            }
            res = (an1 + n * a0 - csum) / (n+1);
        }
        if(first) first = false;
        else putchar('\n');
        printf("%.2lf\n",res);
    }

    return 0;
}
