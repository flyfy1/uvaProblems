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
    int n;

    while(cin >> n){
        int sum = n;
        while(n >= 3){
            sum += n/3;
            n = n/3 + n%3;
        }
        if(n == 2)  sum++;
        cout << sum << endl;
    }

    return 0;
}
