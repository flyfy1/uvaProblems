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
#define UP 1001
#define VAL 1000000

using namespace std;

typedef pair<int,int>   ii;
typedef vector<int>     vi;
typedef vector<ii>      vii;
typedef vector<vi>     vvi;
typedef vector<vii>    vvii;
typedef map<int,int>    mii;

vi ft;
vector<bool> sei(UP,0);

void factorize(int n,map<int,int> &mm){
    int hn = sqrt(n) + 1,idx = 0;
    while(idx < ft.size() && ft[idx] < hn && n > 1){
        int m = ft[idx];
        if(n % m == 0){
            n /= m;
            if(mm.count(m)){
                mm[m] = mm[m]+1;
            } else{
                mm[m] = 1;
            }
        } else  idx++;
    }
    if(n > 1)   mm[n] = 1;
}

short res[VAL+1];

int main(){
    for(int i=2;i<UP;i++){
        if(!sei[i]){
            ft.push_back(i);
            for(int j=2;i*j < UP;j++){
                sei[i*j] = 1;
            }
        }
    }
    sei.clear();

    mii mm;
    res[0] = res[1] = 1;
    int val = 1;
    for(int i=2;i<=VAL;i++){
        mii fac;           
        factorize(i,fac);
        for(mii::iterator it = fac.begin(); it != fac.end();it++){
            if(mm[it->first] < it->second){
                for(int j=0;j<it->second - mm[it->first];j++){
                    val *= it->first;
                    while(val % 10 == 0){
                        val /= 10;
                    }
                    val %= 1000;
                }
                mm[it->first] = it->second;
            }
            res[i] = val%10;
        }
    }

    int n;
    while(cin >> n, n){

        /*
        for(mii::iterator it = mm.begin(); it != mm.end();it++){
            printf("%d,%d  ",it->first,it->second);
        }
        putchar('\n');
        */
        cout << res[n] % 10 << endl;
    }

    return 0;
}
