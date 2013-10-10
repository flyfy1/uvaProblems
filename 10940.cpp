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

int f(int n); int g(int n);

int f(int n){
    if(n == 1) return 1;
    if(n & 1)   return 2*g(n/2);
    else    return 2*f(n/2);
}
int g(int n){
    if(n == 1)  return 1;
    if(n & 1)   return 2*f(n/2+1) - 1;
    else return 2*g(n/2) - 1;
}

int main(){
    int n;
    while(cin >> n,n){
        cout << f(n) << endl;
    }

    return 0;
}
