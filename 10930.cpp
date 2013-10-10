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

int n;
int seq[40];
int fg[1005];

bool occur(int idx, int osum, int nchoice, int lim){
    if(osum > lim){
        return 0;
    }
    if(idx == n)    return 0;
    if(nchoice > 1){
        fg[osum] = 1;
    }
    if(fg[seq[idx]]){
        return 1;
    }
    return occur(idx+1, osum+seq[idx], nchoice+1, lim) ||
           occur(idx+1, osum, nchoice, lim);
}

int main(){
    int CC = 1;
    while(cin >> n){
        int t;
        set<int> sums;
        bool is_a_seq = true;
        for(int i=0;i<n;i++){
            cin >> seq[i];
            if(i > 0 && seq[i] <= seq[i-1])  is_a_seq = false;
        }

        printf("Case #%d:",CC++);
        for(int i=0;i<n;i++){
            printf(" %d",seq[i]);
        }
        putchar('\n');

        if(is_a_seq){
            memset(fg,0,sizeof(fg));
            is_a_seq = !occur(0,0,0,seq[n-1]);
        }

        if(is_a_seq){
            cout << "This is an A-sequence." << endl;
        } else{
            cout << "This is not an A-sequence." << endl;
        }
    }

    return 0;
}
