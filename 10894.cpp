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

using namespace std;

typedef pair<int,int>   ii;
typedef vector<int>     vi;
typedef vector<ii>      vii;
typedef vector<vi>     vvi;
typedef vector<vii>    vvii;
typedef map<int,int>    mii;

char w1[4][5][6] = {
    {   "*****",
        "*....",
        "*****",
        "....*",
        "*****"},

    {   ".***.",
        "*...*",
        "*****",
        "*...*",
        "*...*"},
    
    {   "*...*",
        "*...*",
        "*...*",
        ".*.*.",
        "..*.."},

    {   "*****",
        "*....",
        "***..",
        "*....",
        "*****"},
};
char w2[6][5][6] = {
    {
        "*...*",
        "*...*",
        "*****",
        "*...*",
        "*...*"},
    {
        "*****",
        "*...*",
        "*****",
        "*.*..",
        "*..**"},
    {
        "*****",
        "..*..",
        "..*..",
        "..*..",
        "*****"},
    {
        "***..",
        "*..*.",
        "*...*",
        "*..*.",
        "***.."},
    {
        "*****",
        "*...*",
        "*...*",
        "*...*",
        "*****"},
    {
        "*...*",
        ".*.*.",
        "..*..",
        "..*..",
        "..*.."},
};

void print_hor(int n){
    for(int i=0;i<5;i++){
        for(int t=0;t<n;t++){
            // phrase 1
            for(int j=0;j<4;j++){
                // word 1
                for(int k=0;k<5;k++){
                    // char 1
                    for(int l=0;l<n;l++){
                        putchar(w1[j][i][k]);
                    }
                }
                // space
                for(int l=0;l<n;l++){
                    putchar('.');
                }
            }

            // space
            for(int l=0;l<n;l++){
                putchar('.');
            }

            // phrase 2
            for(int j=0;j<6;j++){
                // space
                for(int l=0;l<n;l++){
                    putchar('.');
                }
                // word 2
                for(int k=0;k<5;k++){
                    // char 2
                    for(int l=0;l<n;l++){
                        putchar(w2[j][i][k]);
                    }
                }
            }
            putchar('\n');
        }
    }
}

void print_ver(int n){
    // phrase
    for(int i=0;i<4;i++){
        // char line
        for(int j=0;j<5;j++){
            // char line mul
            for(int t=0;t<n;t++){
                // char
                for(int k=0;k<5;k++){
                    // char in line mul
                    for(int l=0;l<n;l++){
                        putchar(w1[i][j][k]);
                    }
                }
                putchar('\n');
            }
        }
        // then add in space
        for(int t=0;t<n;t++){
            for(int k=0;k<n;k++){
                for(int l=0;l<5;l++){
                    putchar('.');
                }
            }
            putchar('\n');
        }
    }
    
    // space
    for(int t=0;t<n;t++){
        for(int k=0;k<n;k++){
            for(int l=0;l<5;l++){
                putchar('.');
            }
        }
        putchar('\n');
    }

    // phrase
    for(int i=0;i<6;i++){
        // space
        for(int t=0;t<n;t++){
            for(int k=0;k<n;k++){
                for(int l=0;l<5;l++){
                    putchar('.');
                }
            }
            putchar('\n');
        }
        // char line
        for(int j=0;j<5;j++){
            // char line mul
            for(int t=0;t<n;t++){
                // char
                for(int k=0;k<5;k++){
                    // char in line mul
                    for(int l=0;l<n;l++){
                        putchar(w2[i][j][k]);
                    }
                }
                putchar('\n');
            }
        }
    }
}

int main(){
    int n;
    while(cin >> n, n){
        if(n > 0)   print_hor(n);
        else print_ver(-n);
        printf("\n\n");
    }
    
    return 0;
}
