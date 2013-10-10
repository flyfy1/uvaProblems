#include <iostream>
#include <vector>
#include <string>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#include <set>
#include <stack>
#include <map>

using namespace std;

typedef pair<int,int>   ii;

int main(){
    int N,TC;
    int a,b;
    int t,k;
    vector<int> r,w;
    
    scanf("%d",&TC);
    while(TC--){
        scanf("%*d%*d%d",&N);
        r.clear();w.clear();
        while(N--){
            scanf("%d%d",&a,&b);
            r.push_back(a); w.push_back(b);
        }

        sort(r.begin(),r.end());
        sort(w.begin(),w.end());

        // for(int i=0;i<r.size();i++) printf("%d ",r[i]);
        // putchar('\n');

        int mid = (r.size() + 1) / 2 - 1;
        int rm = r[mid];
        int wm = w[mid];

        printf("(Street: %d, Avenue: %d)\n",rm,wm);
    }

    return 0;
}
