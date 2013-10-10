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
    int N;
    while(cin >> N, N > 0){
        if(N == 1){
            cout << "0%" << endl;
        } else{
            printf("%.0lf%%\n",N/4.0 * 100);
        }
    }

    return 0;
}
