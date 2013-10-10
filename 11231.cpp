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
    int n,m,c;
    while(cin >> n >> m >> c, n | m | c){
        n -= 7; m-=7;
        if(c){
            cout << ((m+1)/2) * ((n+1)/2) + (m/2) * (n/2) << endl;
        } else{
            cout << ((m+1)/2) * (n/2) + (m/2) * ((n+1)/2) << endl;
        }
    }
    return 0;
}
