/**
 * UVA 725 - division
 * Desc: find and display all pairs of 6 digit nums between them use digits 
 *  0 ~ 9 once each, such that abcde/fghij = N where 2 <= N <= 79
 */

#include <iostream>
#define N   4
#define M   3

using namespace std;

// keep history of 0~9
int his[M];
bool mark[N];

void backTrack(int pos){
    if(pos == M){
        // output the result
        for(int i=0;i<M; i++){
            cout << his[i] << " ";
        }
        cout << endl;
    }
    for(int i=0;i<N;i++){
        if(!mark[i]){
            // push into history and backtrack
            his[pos] = i;
            mark[i] = true;
            backTrack(pos + 1);
            mark[i] = false;
        }
    }
}

int main(){
    backTrack(0);
   return 0; 
}
