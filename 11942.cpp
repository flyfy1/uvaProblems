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
    int TC;
    int a[10];
    cin >> TC;
    cout << "Lumberjacks:" << endl;
    while(TC--){
        bool inc = true, dec = true;
        for(int i=0;i<10;i++)   cin >> a[i];
        for(int i=1;i<10;i++)   if(a[i-1] > a[i]) inc = false;
        for(int i=1;i<10;i++)   if(a[i-1] < a[i]) dec = false;
        if(inc || dec)  cout << "Ordered" << endl;
        else cout << "Unordered" << endl;
    }

    return 0;
}
