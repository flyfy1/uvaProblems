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
    char *p;
    char s[] = "Songyy is working hard . Do you know that? I know :)";
    char tok_set[] = " .";

    char as[] = "songyy abc";
    char bs[] = "songyy def";
    cout << strncmp(as,bs,8) << endl;
    
    p = strtok(s,tok_set);
    while(p){
        cout << p << endl;
        p = strtok(NULL,tok_set);
    }

    return 0;
}
