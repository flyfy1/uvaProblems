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
#include <list>
#include <cmath>
#define TMAX 100000
#define PMAX 10000

using namespace std;

typedef pair<int,int>   ii;
typedef vector<int>     vi;
typedef vector<ii>      vii;
typedef vector<vi>     vvi;
typedef vector<vii>    vvii;
typedef map<int,int>    mii;

char P[PMAX], T[TMAX];
int M,N,B[PMAX];

void KmpPreProcess(){
    M = strlen(P); N = strlen(T);
    int i = 0, j = -1;
    B[0] = -1;
    while( i < M){
        while( j > 0 && P[j] != P[i])   j = B[j];
        i++; j++;
        B[i] = j;
    }
}

void KmpSearch(){
    int i = 0, j = 0;
    while(i < N){
        while(j >= 0 && T[i] != P[j])    j = B[j];
        i++; j++;
        if(j == M){
            printf("Find match at position: %d\n",i-j);
        }
    }
}

int main(){
    // strcpy(P,"SONSOENSYY");
    // strcpy(T,"SONGSONG YSLSD KFJQE SONSOE SONSOENSYY");
    strcpy(P,"SONGYY");
    strcpy(T,"TTSSSONGYY");
    KmpPreProcess();
    KmpSearch();

    return 0;
}
