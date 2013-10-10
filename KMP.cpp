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
#define MAX_N 100010

using namespace std;

typedef pair<int,int>   ii;
typedef vector<int>     vi;
typedef vector<ii>      vii;
typedef vector<vi>     vvi;
typedef vector<vii>    vvii;
typedef map<int,int>    mii;

char T[MAX_N], P[MAX_N];
int b[MAX_N],n,m; // b: back table; n: length of T; m: length of P

void kmpPreProcess(){
    int i = 0, j = -1; b[0] = -1;
    n = strlen(T); m = strlen(P);
    while(i<m){ // Pre-process the pattern string P
        while( j >= 0 && P[i] != P[j]) j = b[j];    // if different, reset j using b
        i++; j++;
        b[i] = j;
    }
}

void kmpSearch(){   // similiar as kmpPreProcess, but on string T
    int i = 0, j = 0;   // starting values
    while(i < n){
        while( j >= 0 && T[i] != P[j]) j = b[j]; // if different, reset j using b
        i++; j++;
        if( j == m){
            printf("P is found at index %d in T, matched str: %s\n",i-j,T + i - j);
            j = b[j];   // Prepare j for the next possible match
        }
    }
}

int main(){
    // strcpy(T,"I DO NOT LIKE SEVENTY SEV BUT SEVENTY SEVENTY SEVEN"); 
    strcpy(T,"SONGYY"); 
    //strcpy(P,"SEVENTY SEVEN"); 
    strcpy(P,"SONGYY"); 
    
    kmpPreProcess();
    kmpSearch();

    return 0;
}
