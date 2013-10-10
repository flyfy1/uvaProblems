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

int pb[10000];
int nb[10000];

int main(){
    int R,C,r,t;

    while(scanf("%d%d",&R,&C) != EOF){
        vector<ii> v[C];
        for(int i=0;i<R;i++){
            scanf("%d",&r);
            for(int j=0;j<r;j++)    scanf("%d",&pb[j]);
            for(int j=0;j<r;j++){
                scanf("%d",&t);
                v[pb[j]-1].push_back(make_pair<int,int>(i,t));
            }
        }
        for(int i=0;i<C;i++)    sort(v[i].begin(),v[i].end());

        /*
        // output size here
        for(int i=0;i<C;i++){
            printf("v[i].size = %d\n",v[i].size());
            for(int j=0;j<v[i].size();j++)  printf("%d ",v[i][j].second);
            putchar('\n');
        }*/

        printf("%d %d\n",C,R);
        for(int i=0;i<C;i++){
            printf("%d",v[i].size());
            for(int j = 0;j<v[i].size();j++)    printf(" %d",v[i][j].first + 1);
            putchar('\n');
            bool first = true;
            for(int j = 0;j<v[i].size();j++){
                if(first) first = false; else putchar(' ');
                printf("%d",v[i][j].second);
            }
            putchar('\n');
        }
    }

    return 0;
}
