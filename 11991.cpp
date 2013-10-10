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

#define M_SIZE 1000010

using namespace std;

typedef pair<int,int>   ii;


vector<int> freq[M_SIZE];
int main(){
    int m,n,t,k;
    while(scanf("%d%d",&n,&m) != EOF){
        for(int i=0;i<M_SIZE;i++)   freq[i].clear();
        for(int i=0;i<n;i++){
            scanf("%d",&t);
            freq[t].push_back(i+1);
        }
        for(int i=0;i<m;i++){
            scanf("%d%d",&k,&t);
            printf("%d\n",freq[t].size() >= k ?freq[t][k-1] : 0);
        }
    }
    return 0;
}
