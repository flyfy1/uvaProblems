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
typedef vector<vi>      vvi;

int N;
//int mm[105][105];

int main(){
    int TC,t;
    
    scanf("%d",&TC);
    for(int I=0;I<TC;I++){
        scanf("%d",&N);
        vvi inL(N);
        
        printf("Case %d:\n",I+1);
        for(int i=0;i<N;i++)
            for(int j=0;j<N;j++){
                scanf("%d",&t);
                if(t)   inL[j].push_back(i);
            }
        for(int i=0;i<N;i++){
            putchar('+');
            for(int j=0;j<2*N-1;j++)    putchar('-');
            printf("+\n");
            for(int j=0;j<N;j++){
                putchar('|');
                if(i==j || (inL[j].size() == 1 && inL[j][0] == i))  putchar('Y');
                else putchar('N');
            }
            printf("|\n");
        }
        putchar('+');
        for(int j=0;j<2*N-1;j++)    putchar('-');
        printf("+\n");
    }

    return 0;
}
