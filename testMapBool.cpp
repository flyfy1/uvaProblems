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
    map<int,bool> mp;
    mp[1] = true;
    mp[3] = true;
    cout << mp[0] << endl;
    cout << mp[2] << endl;
    for(map<int,bool>::iterator it = mp.begin();it != mp.end(); it++){
        cout << it->first << endl;
    }

    return 0;
}
