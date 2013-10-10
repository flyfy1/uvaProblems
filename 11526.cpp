#include <iostream>
#include <vector>
#include <string>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#include <set>
#include <stack>
#include <map>
#include <cmath>

using namespace std;

int main(){
    // freopen("in.txt","r",stdin);
    long long t,res;
    int n;

    cin >> n;
    while(n--){
        cin >> t;
        if(t <= 0){
            cout << 0 << endl;
            continue;
        }

        res = 0;

        int divider = sqrt(t);

        for(int i=1;i<=divider;i++){
            res += t / i;
        }

        res -= (t/(divider + 1)) * divider;

        for(int i=1;i<=t/(divider+1); i++){
            res += t / i;
        }

        cout << res << endl;
    }

    return 0;
}
