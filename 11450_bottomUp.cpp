#include <cstdio>
#include <cstring>

using namespace std;

int main(){
    int i,j,l,TC,M,C,price[25][25];
    bool can_reach[210][25];

    scanf("%d",&TC);
    while(TC--){
        scanf("%d%d",&M,&C);
        for(i=0;i<C;i++){
            scanf("%d", &price[i][0]);
            for(j = 1;j<= price[i][0]; j++) scanf("%d",&price[i][j]);
        }
        memset(can_reach,false,sizeof can_reach);
        for(i = 1;i<=price[0][0]; i++)
            can_reach[M - price[0][i]][0] = true;
        for(j = 1; j<C; j++)
            for(i = 0; i < M; i++)  if(can_reach[i][j-1])
                for( l = 1; l <= price[j][0]; l++)  if( i - price[j][l] >= 0)
                    can_reach[i - price[j][l]][j] = true;

        for( i = 0;i<=M && !can_reach[i][C-1]; i++);

        if( i == M + 1) printf("no solution\n");
        else            printf("%d\n", M-i);
    }

    return 0;
}
