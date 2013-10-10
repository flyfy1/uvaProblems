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
#define TMAX 100005
#define PMAX 100005

using namespace std;

typedef pair<int,int>   ii;
typedef vector<int>     vi;
typedef vector<ii>      vii;
typedef vector<vi>     vvi;
typedef vector<vii>    vvii;
typedef map<int,int>    mii;

char P[PMAX], T[TMAX];
char C[TMAX];
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

int KmpSearch(){
    int i = 0, j = 0;
    while(i < N){
        while(j >= 0 && T[i] != P[j])    j = B[j];
        i++; j++;
    }
    return j;
}

int main(){
    while(cin >> T){
        N = strlen(T);      
        T[N] = 0;
        P[N] = 0;
        for(int i=0;i<N;i++){
            P[N-1-i] = T[i];
        }
        KmpPreProcess();
        int j = KmpSearch();
        
        printf("%s",T);
        for(int i=j;i<M;i++){
            putchar(P[i]);
        }
        putchar('\n');
    }
    
    return 0;
}
