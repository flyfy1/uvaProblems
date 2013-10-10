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

char ss[] = "12 |songyy is a a2q3ur wfkb aljkdr qwafblea; lg|\n";

int main(){
    char buf[12];
    int d = 0;
    
    sscanf(ss,"%d %*c%[^|] ",&d,buf);
    printf("%d, %s\n",d,buf);

    return 0;
}
