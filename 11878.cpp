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
    int a,b,c;
    char op;
    char r[100];
    int correct = 0;
    while(scanf("%d%c%d%*c%s",&a,&op,&b,r) == 4){
        if(r[0] == '?') continue;
        sscanf(r,"%d",&c);
        if( op == '+' && a + b == c) correct++;
        else if( op == '-' && a - b == c)   correct++;
    }
    cout << correct << endl;
    
    return 0;
}
