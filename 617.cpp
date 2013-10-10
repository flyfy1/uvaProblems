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

int CS;
float mi[10];
int g[10],y[10],r[10];
int sum[10];

bool correctS(int s){
    for(int i=0;i<CS;i++){
        float f = mi[i] / s * 3600;
        float tr = f - ((int)(f/sum[i]) * sum[i]);
        if(tr > g[i] + y[i])   return false;
    }
    return true;
}

int main(){
    int TC = 1;
    while(scanf("%d",&CS),CS != -1){
        for(int i=0;i<CS;i++){
            scanf("%f%d%d%d",&mi[i],&g[i],&y[i],&r[i]);
            sum[i] = g[i] + y[i] + r[i];
        }
        int cc = 0; 
        int last = -1;
        cout << "Case " << TC++ << ": ";
        bool hasOutput = false;
        for(int s=30;s<=60;s++){
            if(!correctS(s)) continue;
            hasOutput = true;
            if(last == -1){
                cout << s;
                cc++;
            } else if(cc){
                if(s == last + 1){
                    cc++;
                    last = s;
                    continue;
                }

                if(cc > 1){
                    cout << "-" << last;
                } 
                cout << ", " << s;
                cc = 1;
            }
            last = s;
        }
        
        if(cc > 1)  cout << "-" << last;

        if(!hasOutput){
            cout << "No acceptable speeds." << endl;
        } else{
            cout << endl;
        }
    }
    return 0;
}
