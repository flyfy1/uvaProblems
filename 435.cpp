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

using namespace std;

typedef pair<int,int>   ii;
typedef vector<int>     vi;
typedef vector<ii>      vii;

int tt[0xfffff];

int main(){
    int TC;
    cin >> TC;
    int N;
    while(TC--){
        cin >> N;
        vi v(N);
        int sum = 0;
        for(int i=0;i<N;i++){
            cin >> v[i];
            sum += v[i];
        }
        int upper = 1<<N;
        int half = sum/2;
        vi pw(N);
        for(int i=0;i<upper;i++){
            int ts = 0;
            for(int j=0;j<N;j++){
                if(i & (1<<j))  ts += v[j];
            }
            tt[i] = ts;
        }
        for(int k=0;k<N;k++){
            int cc = 0;
            for(int i=0;i<upper;i++){
                if(i & (1<<k))  continue;
                int ts = tt[i];
                if( ( ts <= half) && (ts + v[k] > half)){
                    // printf("ts = %d, val = %x\n",ts,i);
                    cc++;
                }
            }
            pw[k] = cc;
        }
        for(int i=0;i<N;i++){
            printf("party %d has power index %d\n",i+1,pw[i]);
        }
        putchar('\n');
    }

    return 0;
}
