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

using namespace std;

typedef pair<int,int>   ii;
typedef vector<int>     vi;
typedef vector<ii>      vii;

int main(){
    int TC, a[3];
    int CC = 1;
    cin >> TC;
    while(TC--){
        for(int i=0;i<3;i++)    cin >> a[i];
        sort(a,a+3);
        printf("Case %d: %d\n",CC++,a[1]); 
    }

    return 0;
}
