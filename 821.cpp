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

int cost[105][105];

int main(){
    int a,b;
    cin >> a >> b;
    int m;
    int cc = 1;
    do{
        memset(cost,0,sizeof cost);
        map<int,int> mi;
        int co = 0;
        do{
            if(!mi.count(a)) mi[a] = co++;
            if(!mi.count(b)) mi[b] = co++;
            a = mi[a]; b = mi[b];

            cost[a][b] = 1;
        } while(cin >> a >> b, a || b);
        cin >> a >> b;
        
        for(int i=0;i<=co;i++){
            for(int j=0;j<=co;j++){
                if(!cost[i][j]) cost[i][j] = 0xfffff;
            }
        }


        for(int k=0;k<co;k++){
            for(int i=0;i<co;i++){
                for(int j=0;j<co;j++){
                    if(cost[i][k] + cost[k][j] < cost[i][j]){
                        cost[i][j] = cost[i][k] + cost[k][j];
                    }
                }
            }
        }
        
        
        float sum = 0;
        for(int i=0;i<co;i++){
            for(int j=0;j<co;j++){
                if(i==j) continue;
                sum += cost[i][j];
            }
        }
        printf("Case %d: average length between pages = %.3f clicks\n",cc++,sum/co/(co-1));
    } while(a || b);
    return 0;
}
