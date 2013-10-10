// refered to: http://www.algorithmist.com/index.php/UVa_10892

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
#define VAL 50000

using namespace std;

typedef pair<int,int>   ii;
typedef vector<int>     vi;
typedef vector<ii>      vii;
typedef vector<vi>     vvi;
typedef vector<vii>    vvii;
typedef map<int,int>    mii;

bool p[VAL];
vi ft;

void factorize(int n,mii &mp){
    int hn = sqrt(n) + 1;
    int idx = 0;
    while(n > 1 && ft[idx] <= hn){
        if(n % ft[idx] == 0){
            n /= ft[idx];
            if(mp.count(ft[idx])) mp[ft[idx]]++;
            else mp[ft[idx]] = 1;
        }
        else idx++;
    }
    if(n > 1) mp[n] = 1;
    return;
}

int main(){
    memset(p,1,sizeof(p));
    for(int i=2;i<VAL;i++){
        if(!p[i])   continue;
        ft.push_back(i);
        for(int j=i*i;j<VAL;j+=i){
            p[i] = false;
        }
    }

    int n;
    while(cin >> n,n){
        mii mp;
        factorize(n,mp);
        int sum = 1;
        int mul = 1;
        for(mii::iterator it = mp.begin(); it != mp.end();it++){
            sum += it->second * mul; mul *= 2 * it->second + 1;
        }
        cout << n << " " << sum << endl;
    }
    return 0;
}
