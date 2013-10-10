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

int cube[1005];

int main(){
    int a,b;
    for(int i=1;i<1001;i++){
        cube[i] = i * i * i;
    }
    map<int,int> mp;
    for(int i=1;i<1001;i++){
        for(int j=2;j<1001;j++){
            int sum = cube[i] + cube[j];
            if(sum < 1000100001){
                mp[sum]++;
            }
        }
    }
    vector<int> v;
    for(mii::iterator it = mp.begin(); it != mp.end(); it++){
        if(it->second > 2)  v.push_back(it->first);
    }
    while(cin >> a >> b){
        vi::iterator ita = lower_bound(v.begin(),v.end(),a);
        vi::iterator itb = lower_bound(v.begin(),v.end(),a+b);

        if(itb != v.end() && *itb == a+b) itb++;
        if(ita == itb){
            cout << "None" << endl;
            continue;
        }
        while(ita != itb){
            cout << *ita << endl;
            ita++;
        }
    }

    return 0;
}
