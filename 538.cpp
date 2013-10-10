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

int N,T,CC=1;
string sv[20];
int cv[20];

int main(){
    while(cin >> N >> T, N || T){
        map<string,int> mp;
        memset(cv,0,sizeof cv);
        int a,b,val; string as, bs;
        for(int i=0;i<N;i++){
            cin >> as;
            sv[i] = as;
            mp[as] = i;
        }
        for(int i=0;i<T;i++){
            cin >> as >> bs >> val; 
            cv[mp[as]] -= val; cv[mp[bs]] += val;
        }

        int pidx = 0, midx = 0,mv;
        cout << "Case #" << CC++ << endl;
        while(true){
            while(cv[pidx] <= 0 && pidx < N) pidx++;
            while(cv[midx] >= 0 && midx < N) midx++;
            if(pidx >= N || midx >= N)  break;
            mv = min(cv[pidx],-cv[midx]);
            cv[pidx] -= mv; cv[midx] += mv;
            cout << sv[pidx] << " " << sv[midx] << " " << mv << endl;
        }
        cout << endl;
    }

    return 0;
}
