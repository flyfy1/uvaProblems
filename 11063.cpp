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

int main(){
    int CC = 1;
    while(cin >> n){
        int t;
        set<int> sums;
        bool is_seq = true;
        for(int i=0;i<n;i++){
            cin >> seq[i];
            if(seq[i] < 1)  is_seq = false;
            if(i > 0 && seq[i] <= seq[i-1])  is_seq = false;
        }

        for(int i=0;i<n && is_seq;i++){
            for(int j=i;j<n;j++){
                int sum = seq[i] + seq[j];
                if(sums.count(sum) > 0){
                    is_seq = false;
                    goto output;
                }
                sums.insert(seq[i] + seq[j]);
            }
        }
output:
        printf("Case #%d: ",CC++);
        if(is_seq){
            cout << "It is a B2-Sequence." << endl;
        } else{
            cout << "It is not a B2-Sequence." << endl;
        }
        cout << endl;
    }

    return 0;
}
