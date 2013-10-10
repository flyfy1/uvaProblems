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

char guessN[12][5];
int  NC[12],NI[12];
int G;
bool checked[10];

bool testCond(int u){
    // cout << "u = " << u << endl;
    for(int i=0;i<G;i++){
        memset(checked,0,sizeof checked);
        int r = u,ac = 0, wp = 0;
        // first check ac
        for(int j=0;j<4;j++){
            int n = r%10; r/=10;
            if(n == (guessN[i][3-j] - '0')){
                checked[n] = 1;
                ac++;
            }
        }
        r = u;
        for(int j=0;j<4;j++){   // test based on each digit
            int n = r%10; r/=10;
            if(checked[n])   continue;
            for(int k=0;k<4;k++){
                if(n == (guessN[i][3-k] - '0')){
                    wp++; break;
                }
            }
        }
        if((ac != NC[i]) || (wp != NI[i])){
            //cout << " failing case, i = " << i << " , ac = " << ac << ", wp = " << wp  << ", num= " << guessN[i] << endl;
            return false;
        }
    }
    return true;
}

int main(){
    int TC;
    

    scanf("%d",&TC);
    while(TC--){
        scanf("%d",&G);
        for(int i=0;i<G;i++)    {
            scanf("%s %d/%d",guessN[i],NC + i,NI + i);
        }
        //testCond(9131);while(1);
        // cout << "done reading" << endl;
        int num = -1; bool dup = 0;
        for(int i=0;i<10000;i++){
            if(testCond(i)){
                if(num != -1){
                    dup = true;
                    break;
                }
                num = i;
            }
        }
        // cout << "done one case " << endl;

        if(dup) printf("indeterminate\n");
        else if(num == -1)    printf("impossible\n");
        else{
            char rres[6];
            for(int i=0;i<4;i++){
                rres[3-i] = num%10 + '0';
                num /= 10;
            }
            rres[4] = 0;
            printf("%s\n",rres);
        }
    }
    return 0;
}
