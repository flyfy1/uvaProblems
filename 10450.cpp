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
#define VAL 53

using namespace std;

typedef pair<int,int>   ii;
typedef vector<int>     vi;
typedef vector<ii>      vii;
typedef vector<vi>     vvi;
typedef vector<vii>    vvii;
typedef map<int,int>    mii;

long long arr[VAL];

int main(){
    arr[0] = arr[1] = 1;
    for(int i=2; i<VAL;i++)  arr[i] = arr[i-1] + arr[i-2];
    int n;
    int TC;
    cin >> TC;
    for(int I=0;I<TC;I++){
        cin >> n;
        printf("Scenario #%d:\n%lld\n\n",I+1,arr[n+1]);
    }
    return 0;
}
