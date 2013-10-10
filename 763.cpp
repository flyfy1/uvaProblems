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

unsigned long long fib[101];

int main(){
    fib[0] = 1; fib[1] = 2;
    for(int i=2;i<101;i++){
        fib[i] = fib[i-1] + fib[i-2];
        cout << fib[i] << endl;
    }
    return 0;
}
