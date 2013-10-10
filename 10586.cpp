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
    int n,k;
    while(cin >> n >> k, k >= 0){
        int idx = 0;
        vector<long long> A(n+1);
        for(int i=0;i<=n;i++){
            cin >> A[i];
        }
        reverse(A.begin(),A.end());

        while(A[idx] == 0 && idx < A.size()){
            idx++; n--;
        }

        while( n >= k){
            A[idx+k] -= A[idx];
            idx++; n--;
        }

        while(A[idx] == 0 && idx < A.size()){
            idx++; n--;
        }
        
        stack<long long> S;
        while(idx < A.size()){
            S.push(A[idx]); idx++;
        }
        bool first = true;
        while(!S.empty()){
            if(first)   first = false;
            else    putchar(' ');
            printf("%lld",S.top());
            S.pop();
        }
        if(first)   cout << 0;
        putchar('\n');
    }

    return 0;
}
