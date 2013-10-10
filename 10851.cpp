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
    int TC;
    string buf;

    cin >> TC;
    getline(cin,buf);
    while(TC--){
        vector<string> vv;
        while(getline(cin,buf), buf != ""){
            vv.push_back(buf);
        }
        for(int i=1;i<vv[0].length()-1;i++){
            char c = 0;
            for(int j=8;j>0;j--){
                c <<= 1;
                if(vv[j][i] == '\\'){
                    c += 1;
                }
            }
            putchar(c);
        }
        putchar('\n');
    }

    return 0;
}
