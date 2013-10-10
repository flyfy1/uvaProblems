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

int pw10[10];
int n;

int search_one_level(queue<ii> &qs,map<int,int> &ms, map<int,int> &mtar){
    int level = qs.front().second;
    while(!qs.empty()){
        int u = qs.front().first;
        int c = qs.front().second;
        if(mtar[u]){
            return mtar[u] + c - 2;
        }
        if(c > level){
            break;
        }
        qs.pop();

        for(int l=1;l<n;l++){
            for(int i=0;i<n-l+1;i++){
                int npart = (u/pw10[i])%pw10[l];
                int newu = (u%pw10[i]) + (u/pw10[i+l]*pw10[i]);
                for(int j=0;j<n-l;j++){
                    int newn = (newu/pw10[j]*pw10[l]+npart)*pw10[j]+newu%pw10[j];
                    if(ms[newn])   continue;
                    if(mtar[newn]){
                        return mtar[newn] + c - 1;
                    }
                    qs.push(ii(newn,c+1));
                    ms[newn] = c+1;
                }
            }
        }
    }
    return -1;
}
int main(){
    int t;
    int num;
    int base = 1;
    int CC = 1;
    for(int i = 0;i<10;i++){
        pw10[i] = base;
        base *= 10;
    }

    while(cin >> n,n){
        int tar = 0;
        base = 0;
        for(int i=0;i<n;i++){
            base *= 10; tar*=10;
            tar += i+1;
            cin >> t;
            base += t;
        }

        map<int,int> ms;    // shift by 1
        map<int,int> me;    // shift by 1
        queue<ii> qs,qe;
        ms[base] = 1; qs.push(ii(base,1));
        me[tar] = 1; qe.push(ii(tar,1));

        int match = -1;
        for(int level=0;level<2;level++){
            match = search_one_level(qs,ms,me);
            if(match != -1) break;
            match = search_one_level(qe,me,ms);
            if(match != -1) break;
        }

        if(match == -1) match = 5;
        printf("Case %d: %d\n",CC++,match);
    }

    return 0;
}
