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

vector<bool> is_prime(65005,true);
long long pwt[65005];

int factor;

long long pw_mod(int base,int pw){
    if(pw == 1) return base;
    if(pw == 0) return 1;
    long long former_res = pw_mod(base,pw/2);
    former_res = (former_res * former_res) % factor;
    if(pw&1)    former_res = (former_res * base) % factor;
    return former_res;
}

bool is_carmichael(int n){
    if(is_prime[n])  return false;
    factor = n;
    for(int i=2;i<n;i++){
        if(pw_mod(i,n) != i)  return false;
    }
    return true;
}

int main(){
    for(int i=2;i<is_prime.size();i++){
        if(!is_prime[i])  continue;
        for(int j=i*i;j > 0 && j<65005;j+=i){
            is_prime[j] = false;
        }
    }

    int n;
    while(cin >> n,n){
        if(is_carmichael(n)){
            printf("The number %d is a Carmichael number.\n",n);
        } else{
            printf("%d is normal.\n",n);
        }
    }

    return 0;
}
