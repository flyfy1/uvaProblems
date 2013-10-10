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
#define VAL 1000010

using namespace std;

typedef pair<int,int>   ii;
typedef vector<int>     vi;
typedef vector<ii>      vii;
typedef vector<vi>     vvi;
typedef vector<vii>    vvii;
typedef map<int,int>    mii;

vector<bool> pmt(VAL,true);
vector<long long> fpt;

int main(){
    for(int i =2;i<VAL;i++){
        if(!pmt[i]) continue;
        for(int j=2;j * i < VAL; j++){pmt[j*i] = false; }
    }
    for(int i=2;i<VAL;i++){
        if(pmt[i]){
            for(int j=2;true;j++){
                long long val = round(pow(i,j));
                if(val >= 1000000000000ll)  break;
                fpt.push_back(val);
            }
        }
    }
    sort(fpt.begin(),fpt.end());

    int tc;
    long long a,b;
    vector<long long>::iterator ia,ib;
    cin >> tc;
    while(tc--){
        cin >> a >> b;
        ia = lower_bound(fpt.begin(),fpt.end(),a);
        ib = upper_bound(fpt.begin(),fpt.end(),b);
        cout << (ib - ia) << endl;
    }

    return 0;
}
