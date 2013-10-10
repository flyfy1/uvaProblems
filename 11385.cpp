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

int TC,N;
mii mm;

long long fibt[150];
int post[110];

char tarr[100];

int main(){
    fibt[1] = 1; fibt[2] = 2;
    mm[1] = 1; mm[2] = 2;
    for(int i=3;1;i++){
         fibt[i] = fibt[i-2] + fibt[i-1];
        if(fibt[i] > (1ll<<32)) break;
        mm[fibt[i]] = i;
    }

    cin >> TC;
    while(TC--){
        cin >> N;
        int t;
        for(int i=0;i<N;i++){
            cin >> t;
            post[i] = mm[t];
        }
       
        string s;
        getline(cin,s);
        getline(cin,s);

        int posidx= 0,maxIdx = -1;
        memset(tarr,' ',sizeof tarr);
        for(int i=0;i<s.length() && posidx < N;i++){
            if(isupper(s[i])){
                maxIdx = max(maxIdx,post[posidx]);
                tarr[post[posidx++]] = s[i];
            }
        }
        tarr[maxIdx+1] = 0;
        printf("%s\n",tarr+1);
    }

    return 0;
}
