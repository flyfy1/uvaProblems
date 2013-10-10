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

long long base[] = 
    {   100000000000000,
        1000000000000,  10000000000,    1000000000,
        10000000,       100000,         1000,
        100,            1};
char str[][10] = 
    {   " kuti",         
        " lakh",         " hajar",        " shata",
        " kuti",         " lakh",         " hajar",
        " shata",        ""};

int main(){
    long long n;
    double nn;
    int CC = 1;
    while(cin >> nn){
        n = nn;
        printf("%4d.",CC++);
        if(n == 0){
            cout << " 0" << endl;
            continue;
        }
        int ln = 9;
        for(int i=0;i < 9;i++){
            if(n / base[i] > 0){
                if(i > 4 && ln < 4){
                    cout << " kuti";
                }
                ln = i;
                cout << " " << n/base[i] << str[i];
                n = n % base[i];
            }
        }
        if(ln < 4)  cout << " kuti";
        cout << endl;
    }

    return 0;
}
