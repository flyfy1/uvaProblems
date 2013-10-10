#include <iostream>
#include <vector>
#include <string>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#include <set>

using namespace std;

int main(){
//    freopen("11849.in","r",stdin);
    int a,b,t;
    vector<int> v;

    while(cin >> a >> b, a && b){
        v.clear();
        for(int i=0;i<a;i++){
            cin >> t;
            v.push_back(t);
        }

        int sum = 0;
        for(int i=0;i<b;i++){
            cin >> t;
            if(binary_search(v.begin(),v.end(),t)){
                sum++;
            }
        }

        cout << sum << endl;
    }

    return 0;
}
