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

typedef pair<int,string> is;

int main(){
    int TC;
    string buf;
    int r;
    int CC = 1;

    cin >> TC;
    while(TC--){
        vector<is> v;
        int hr = -2000000000;
        for(int i = 0;i<10;i++){
            cin >> buf >> r;
            if(hr < r)  hr = r;
            v.push_back(is(r,buf));
        }
        printf("Case #%d:\n",CC++);
        for(int i = 0;i < 10;i++){
            if(hr == v[i].first){
                cout << v[i].second << endl;
            }
        }
    }

    return 0;
}
