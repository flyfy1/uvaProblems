#include <iostream>
#include <cstring>
#include <cstdio>

using namespace std;

int main(){
    int n;
    char buf[2][10];
    int tn;
    while(cin >> n, n != 0){
        printf("Printing order for %d pages:\n",n);
        int top = n/4 + (n%4 != 0 );
        int upper_count = top*4;
        int lower_count = 1;
        for(int i=0;i<top;i++){

            tn = upper_count--;
            if(tn > n) strcpy(buf[0],"Blank");
            else sprintf(buf[0],"%d",tn);

            tn = lower_count++;
            sprintf(buf[1],"%d",tn);

            printf("Sheet %d, front: %s, %s\n",i+1,buf[0],buf[1]);

            int blank_count = 0;
            tn = lower_count++;
            if(tn > n){
                strcpy(buf[0],"Blank");
                blank_count++;
            }
            else sprintf(buf[0],"%d",tn);

            tn = upper_count--;
            if(tn > n){
                strcpy(buf[1],"Blank");
                blank_count++;
            }
            else sprintf(buf[1],"%d",tn);

            if(blank_count < 2){
                printf("Sheet %d, back : %s, %s\n",i+1,buf[0],buf[1]);
            }

        }
    }
    return 0;
}
