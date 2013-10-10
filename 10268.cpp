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
    long long a;
    while(cin >> a){
        string buf;

        getline(cin,buf);
        getline(cin,buf);

        istringstream in(buf);
        vector<long long> lst;long long co;

        while(in >> co){
            lst.push_back(co);
        }
        int sz = lst.size() - 1;
        long long res = 0;
        for(int i=0;i<lst.size()-1;i++){
            res *= a;
            res += sz * lst[i];
            sz--;
        }
        cout << res << endl;
    }

    return 0;
}
