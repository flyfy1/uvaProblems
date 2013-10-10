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


int main(){
    int hmax,lmin;
    char arr[101][50];
    char endPos[101];
    int TC;
    int CC = 1;
    string buf;
    cin >> TC;
    getline(cin,buf);
    while(TC--){
        memset(arr,' ',sizeof arr);
        getline(cin,buf);
        int cur = 50;
        bool inLow = false;
        hmax = 50; lmin = 51;
        for(int i=0;i<buf.length();i++){
            switch(buf[i]){
                case 'R':
                    cur++;
                    arr[cur][i] = '/';
                    inLow = false;
                    hmax = max(hmax,cur);
                    break;
                case 'C':
                    arr[cur+1][i] = '_';
                    if(inLow) lmin = min(lmin, cur+1);
                    else    hmax = max(hmax,cur+1);
                    break;
                case 'F':
                    arr[cur][i] = '\\';
                    lmin = min(lmin,cur);
                    inLow = true;
                    cur--;
                    break;
            }
        }


        for(int i=hmax;i>=lmin;i--){
            for(int j=0;j<buf.length();j++){
                if(arr[i][j] != ' ')    endPos[i] = j;
            }
        }
        

        printf("Case #%d:\n",CC++);
        for(int i=hmax; i>= lmin; i--){
            printf("| ");
            for(int j=0; j <= endPos[i];j++){
                putchar(arr[i][j]);
            }
            putchar('\n');
        }
        printf("+-");
        for(int j=0; j < buf.length()+1;j++){
            putchar('-');
        }
        printf("\n\n");
    }

    return 0;
}
