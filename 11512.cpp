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
#define  LEN 100005

using namespace std;

typedef pair<int,int>   ii;
typedef vector<int>     vi;
typedef vector<ii>      vii;
typedef vector<vi>     vvi;
typedef vector<vii>    vvii;
typedef map<int,int>    mii;

char S[LEN],R[LEN];

int main(){
    while(cin >> S){
        int l = strlen(S);
        for(int i=0;S[i];i++){
            R[l-1-i] = S[i];
        }
    }
    return 0;
}
