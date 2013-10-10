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
    int N,K,P;
    int tc,CC=1;
    cin >> tc;
    while(tc--){
        cin >> N >> K >> P;
        int r = (K + P)%N;
        if(r == 0)  r = N;
        cout << "Case " << CC++ << ": " << r << endl;
    }

    return 0;
}
