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
    string s;

    n = 0;
    getline(cin,s);
    while(getline(cin,s),s != "___________"){
        int c = 0;
        for(int i=2;s[i] != '|';i++){
            if(s[i] == '.') continue;
            c <<= 1;
            if(s[i] == 'o') c += 1;
        }
        putchar(c);
    }

    return 0;
}
