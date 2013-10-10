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
    int tbl[11];
    tbl[0] = tbl[1] = 1;
    for(int i=2;i<11;i++){
        tbl[i] = tbl[i-1] * (4*i - 2) / (i + 1);
    }
    int n;
    bool first = true;

    while( cin >> n){
        if(first) first = false; else cout << endl;
       cout << tbl[n] << endl;
    }
    return 0;
}
