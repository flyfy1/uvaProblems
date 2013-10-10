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

vi transed;

int get_min_poss_base_and_trans(string str){
    int min_n = 1;
    transed = vi();
    for(int i=0;i<str.size();i++){
        char c = str[i];
        if(c >= '0' && c <= '9'){
            transed.push_back(c-'0');
        } else if(c >= 'A' && c <= 'Z'){
            transed.push_back(c-'A' + 10);
        } else if(c >= 'a' && c <= 'z'){
            transed.push_back(c-'a' + 36);
        } else{
            continue;
        }

        min_n = max(min_n,transed.back());
    }
    return min_n + 1;
}

bool is_divisible(int base){
    int res = 0;
    for(int i=0;i<transed.size();i++){
        res *= base;
        res += transed[i];
        res %= (base-1);
    }
    return res == 0;
}

int main(){
    string buf;
    while(cin >> buf){
        int min_n = get_min_poss_base_and_trans(buf);
        while(!is_divisible(min_n) && min_n <= 62)  min_n++;
        if(min_n > 62)  cout << "such number is impossible!" << endl;
        else cout << min_n << endl;
    }

    return 0;
}
