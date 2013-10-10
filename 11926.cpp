#include <cstdio>
#include <vector>
#include <string>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>
#include <set>
#include <stack>
#include <map>

#define MAX_T 1000001

using namespace std;

bool v[MAX_T];

int main(){

    int m,n,i;
    int start,end,interval;
    int conflict = 0;

    while( (scanf("%d%d",&n,&m)),(m || n) ){

        conflict = 0;
        memset(v,0,sizeof(v));

        while(n--){
            scanf("%d%d",&start,&end);
            if(conflict) continue;

            for(i = start;i<end && i < 1000001;i++){
                if(v[i]){
                    conflict = 1;
                    break;
                }

                v[i] = 1;
            }
        }

        while(m--){
            scanf("%d%d%d",&start,&end,&interval);
            if(conflict) continue;

            while( (start < MAX_T) && !conflict){
                for(i=start; (i<end) && (i < MAX_T);i++){
                    if(v[i]){
                        conflict = 1;
                        break;
                    }
                    v[i] = 1;
                }
                start += interval;
                end += interval;
            }
        }

        if(conflict)    printf("CONFLICT\n");
        else            printf("NO CONFLICT\n");
    }

    return 0;
}
