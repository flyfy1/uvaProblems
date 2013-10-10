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

bool is_kaprekar_num(int n){
    int nsq = n*n;
    // split and sum
    int base = 10;
    while(nsq >= base){
        int b = nsq % base;
        int a = nsq / base;
        if(a && b && a + b == n)    return true;
        base *= 10;
    }
    return false;
}

int main(){
    int a,b;
    int TC;
    cin >> TC;

    vi v;
    
    for(int i=4;i<=40000;i++){
        if(is_kaprekar_num(i)) v.push_back(i);
    }

    int CC = 1;
    bool first = true;
    while(TC--){
        cin >> a >> b;
        vi::iterator ita,itb;
        ita = lower_bound(v.begin(),v.end(),a);
        itb = lower_bound(v.begin(),v.end(),b+1);
        if(first) first = false;
        else putchar('\n');
        printf("case #%d\n",CC++);
        if(ita == itb){
            cout << "no kaprekar numbers" << endl;
            continue;
        }
        while(ita != itb){
            cout << *ita << endl;
            ita++;
        }
    }

    return 0;
}
