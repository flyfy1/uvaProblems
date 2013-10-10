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
    long long S,D;
    while(cin >> S >> D){
        long long M = S * (S-1) + 2 * D;
        long long T = sqrt(M);
        if(T * (T + 1) < M) T++;
        cout << T << endl;
    }

    return 0;
}
