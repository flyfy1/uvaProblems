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

long long C[51][51];

int main(){
    int TC;
    string buf;
    char a[101];
    char b[101];
    char c[10];
    int pos;

    // table of binominal numbers
    C[0][0] = 1;
    for(int n = 1; n < 51; n++){
        C[n][0] = 1;
        for(int k = 1;k <= n; k++){
            C[n][k] = C[n-1][k-1] + ((n-1 >= k)?C[n-1][k]:0);
        }
    }

    /*
    for(int n=1; n < 10; n++){
        for(int k=0;k<=n;k++){
            cout << C[n][k] << " ";
        }
        cout << endl;
    }
    */

    cin >> TC;
    getline(cin,buf);
    for(int I = 1; I <= TC; I++){
        cout << "Case " << I << ": ";
        getline(cin,buf);
        for(pos = 1; isalpha(buf[pos]);pos++)   a[pos-1] = buf[pos];
        a[pos-1] = 0;
        int oldP = pos + 1;
        for(pos = oldP; isalpha(buf[pos]);pos++)   b[pos-oldP] = buf[pos];
        b[pos-oldP] = 0;
        oldP = pos + 2;
        for(pos = oldP; isdigit(buf[pos]);pos++)    c[pos-oldP] = buf[pos];
        c[pos-oldP] = 0;
        int pw = atoi(c);
        bool needPlus = false;
        for(int i=0;i<=pw;i++){
            bool needMul = false;
            if(needPlus) putchar('+');
            if(C[pw][i] > 1){
                printf("%lld",C[pw][i]);
                needMul = true;
            }
            if(pw - i > 0){
                if(needMul) putchar('*');
                printf("%s",a);
                needMul = true;
                needPlus = true;
            }
            if(pw - i > 1){
                printf("^%d",pw - i);
            }
            if(i > 0){
                if(needMul) putchar('*');
                printf("%s",b);
                needMul = true;
                needPlus = true;
            }
            if(i > 1){
                printf("^%d",i);
            }
        }
        putchar('\n');
    }

    return 0;
}
