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

int main(){
    int base = 1;
    for(int i=0;i<10;i++){
        pw10[i] = base; base *= 10;
    }
    int cnt = 1;
    base = 9;
    
    int N;
    while(cin >> N){
        base = 9; cnt = 1;
        while(N > base * cnt){
            N -= base * cnt;
            base *= 10; cnt++;
        }

        int R = N % cnt;
        N = (N-1)/cnt + pw10[cnt-1];
        cout << (N/pw10[(cnt-R)%cnt])%10 << endl;
    }

    return 0;
}
