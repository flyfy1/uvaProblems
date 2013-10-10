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

int N[7];
int sl = 0;

void HandleN1(){
    if(N[1] <= sl)  N[1] = 0;
    else    N[1] -= sl;
    sl = 0; // sl should have no use after this
}
void HandleN2(){
    if(N[2] <= sl){
        sl -= N[2];
        N[2] = 0;
    } else{
        N[2] -= sl;
        sl = 0;
    }
}

int c3map[] = {0,19,15,11,9,5,3,1};

bool all0(){
    for(int i=1;i<=6;i++)   if(N[i])    return false;
    return true;
}

int main(){
    while(true){
        for(int i=0;i<6;i++){
            scanf("%d",&N[i+1]);
        }
        if(all0())   break;

        long s = 0;
        s += N[6];  
        s += N[5]; sl = N[5] * (216-125); HandleN1();
        s += N[4]; sl = N[4] * (216-64)/8; HandleN2(); sl *= 8; HandleN1();

        // case of 3
        int r3 = N[3] % 8;
        s += N[3]/8 + (r3 > 0); sl = c3map[r3]; HandleN2();
        sl *= 8; sl += 216 - r3*27 - c3map[r3]*8; HandleN1();
        int r2 = N[2] % 27;
        s += N[2]/27 + (r2 > 0);sl = 216 - r2 * 8; HandleN1();
        s += N[1]/216 + (N[1]%216 > 0);
        cout << s << endl;
    }
    return 0;
}
