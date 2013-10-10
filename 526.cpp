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

int vct[100][100];
int opt[100][100];

char a[100],b[100];

int cal(int i,int j){
    if(i == 0)  return j;
    if(j == 0)  return i;
    if(vct[i][j] != -1)  return vct[i][j];
    
    int mm = cal(i,j-1) + 1;int op = 1; // add char for a
    int t = cal(i-1,j) + 1;
    if(mm > t){
        mm = t;
        op = 2; // remove char fron b
    }

    t = cal(i-1,j-1) + (a[i] != b[j]);
    if(mm > t){
        mm = t;
        op = (a[i] == b[i])?0:3;    // no-op (0), or replace (3)
    }
    
    opt[i][j] = op;
    return vct[i][j] = mm;
}

int CTT = 0;
void trace_back(int i,int j){
    if(opt[i][j] == -1)    return;
    if(opt[i][j] == 0){
        trace_back(i-1,j-1);
        return;
    }

    if(opt[i][j] == 1){
        trace_back(i,j-1);
        printf("%d ",CTT++);
        printf(" i = %d, j = %d. ",i,j);
        printf("Insert %d,%c\n",i,b[j]);
    } else if(opt[i][j] == 2){
        trace_back(i-1,j);
        printf("%d ",CTT++);
        printf(" i = %d, j = %d. ",i,j);
        printf("Delete %d\n",i);
    } else if(opt[i][j] == 3){
        trace_back(i-1,j-1);
        printf("%d ",CTT++);
        printf(" i = %d, j = %d. ",i,j);
        printf("Replace %d,%c\n",i,b[j]);
    }
}

int main(){
    bool first = true;
    while(cin >> a >> b){
        if(first) first = false;
        else putchar('\n');
        memset(vct,-1,sizeof vct);
        memset(opt,-1,sizeof opt);
        int alen = strlen(a), blen = strlen(b);
        cout << cal(alen,blen) << endl;
        // then trace back to get ops
        CTT = 1;
        trace_back(alen,blen);
    }
    return 0;
}
