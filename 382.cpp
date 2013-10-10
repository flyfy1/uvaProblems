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
#define MXN 60000

using namespace std;

typedef pair<int,int>   ii;
typedef vector<int>     vi;
typedef vector<ii>      vii;
typedef vector<vi>     vvi;
typedef vector<vii>    vvii;
typedef map<int,int>    mii;

bool tft[MXN];
vector<int> ft;

vector<ii> factorize(int n){
    map<int,int> mp;
    int idx = 0;
    while(n > 1 && idx < ft.size() && ft[idx] < n){
        if(n % ft[idx] == 0){
            mp[ft[idx]]++;
            n /= ft[idx];
        }
        else    idx++;
    }
    if(n != 1)  mp[n]++;

    vii vt;
    for(mii::iterator it = mp.begin(); it != mp.end(); it++){
        vt.push_back(ii(it->first,it->second));
    }
    return vt;
}

int sum = 0;
void get_sum_helper(vii fp, int base, int idx){
    if(idx == fp.size()){
        sum += base;
        return;
    }
    for(int i=0; i<=fp[idx].second; i++){
        get_sum_helper(fp,base * ((int) (pow((double)fp[idx].first,i) + 0.5)),idx+1);
    }
}
int get_sum(vii fp,int n){
    sum = 0;
    get_sum_helper(fp,1,0);
    sum -= n;
    return sum;
}

int main(){
    memset(tft,true,sizeof tft);
    ft.clear();
    for(long long i=2;i<MXN;i++){
        if(!tft[i]) continue;
        ft.push_back(i);
        for(long long j=i*i;j<MXN;j+=i){
            tft[j] = false;
        }
    }

    int n;
    printf("PERFECTION OUTPUT\n");
    while(cin >> n,n){
        vii fb = factorize(n);
        int sum = get_sum(fb,n);
        printf("%5d  %s\n",n,(n == sum)?"PERFECT":(n > sum)?"DEFICIENT":"ABUNDANT");
    }
    printf("END OF OUTPUT\n");

    return 0;
}
