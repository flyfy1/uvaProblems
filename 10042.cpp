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

#define VAL 100005

using namespace std;

typedef pair<int,int>   ii;
typedef vector<int>     vi;
typedef vector<ii>      vii;
typedef vector<vi>     vvi;
typedef vector<vii>    vvii;
typedef map<int,int>    mii;

vector<bool> is_prime(VAL,true);
vi ft;

int get_digit_sum(int n){
    int sum = 0;
    while(n > 0){
        sum += n%10; n /= 10;
    }
    return sum;
}

// return true if it's prime number
bool factorize(int n,map<int,int>& fac){
    int hf = sqrt(n) + 1;
    int idx = 0;
    int on = n;
    while(idx < ft.size() && ft[idx] < hf && n > 1){
        if(n % ft[idx] == 0){
            n /= ft[idx]; fac[ft[idx]] ++;
        } else{
            idx ++;
        }
    }
    if(n != 1)  fac[n]++;
    return n == on;
}

int main(){
    for(int i=2;i<VAL;i++){
        if(!is_prime[i])    continue;
        ft.push_back(i);
        for(int j=i*i;j>0 && j<VAL;j+=i){
            is_prime[j] = false;
        }
    }
    
    int TC,n;
    cin >> TC;
    while(TC--){
        cin >> n;
        while(true){
            n++;
            mii fcs;
            if(factorize(n,fcs))    continue;
            int fdsum = 0;
            for(mii::iterator it = fcs.begin(); it != fcs.end(); it++){
                fdsum += get_digit_sum(it->first) * it->second;
            }
            if(fdsum == get_digit_sum(n)){
                cout << n << endl;
                break;
            }
        }
    }

    return 0;
}
