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

int afre[26],bfre[26];

void getFre(string s,int fre[]){
    for(int i=0;i<s.length();i++){
        fre[s[i]-'a']++;
    }
}

int main(){
    string a,b;

    while(getline(cin,a) && getline(cin,b)){
        memset(afre,0,sizeof afre);
        memset(bfre,0,sizeof bfre);
        getFre(a,afre);
        getFre(b,bfre);
        
        for(int i=0;i<26;i++){
            int n = min(afre[i],bfre[i]);
            for(int j=0;j<n;j++)    putchar('a' + i);
        }
        putchar('\n');
    }

    return 0;
}
