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
#define VAL 1005

using namespace std;

typedef pair<int,int>   ii;
typedef vector<int>     vi;
typedef vector<ii>      vii;
typedef vector<vi>     vvi;
typedef vector<vii>    vvii;
typedef map<int,int>    mii;

int arr[VAL];

int main(){
    arr[0] = arr[1] = 1;
    for(int i=2; i<VAL;i++)  arr[i] = arr[i-1] + arr[i-2];
    int n;
    while(cin >> n , n){
        cout << arr[n+1] << endl;
    }
    return 0;
}
