#include <cmath>
#include <cstdio>
#include <cstring>

using namespace std;

int row[9], TC,a,b,lineCounter;

bool place(int col, int tryRow){
    for(int prev = 1; prev < col; prev++){
        if(row[prev] == tryRow || (abs(row[prev] - tryRow) == abs(prev - col))) return false;
    }
    return true;
}

void backTrack(int col){
    for(int tryRow = 1; tryRow <= 8; tryRow++){
        if(place(col,tryRow)){
            row[col] = tryRow;
            if(col == 8 && row[b] == a){    // solution got, output it
                printf("%2d %d", ++lineCounter, row[tryRow]);
                for(int j=2; j<=8; j++) printf("    %d", row[j]);
                printf("\n");
            } else{
                backTrack(col + 1);
            }
        }
    }
}

int main(){
    scanf("%d", &TC);
    while(TC--){
        scanf("%d %d",&a, &b);
        memset(row,0,sizeof row); lineCounter = 0;
        printf("SOLN    COLUMN\n");
        printf(" #  1 2 3 4 5 6 7 8\n\n");
        backTrack(1);   // generate all possible 8! candidate solution
        if(TC)  printf("\n");
    }
    return 0;
}
