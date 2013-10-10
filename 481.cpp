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

using namespace std;

typedef pair<int,int>   ii;
typedef vector<int>     vi;
typedef vector<ii>      vii;

int N;

int main(){
    int t;
    vi arr;
    while(scanf("%d",&t)==1){
        arr.push_back(t);
    }
    
    N = arr.size();
    vi lis(N,1), p(N), D(N,-1);
    int mdx = 0;
    p[0] = 0; D[1] = 0;
    for(int i=1;i<N;i++){
        p[i] = i;
        // use binary search here
        int s = 1, e = lis[mdx],l;
        while(s < e){
            l = (s+e) / 2;
            if(arr[i] > arr[D[l]]) s = l + 1;
            else                   e = l - 1;
        }
        if(!(arr[i] > arr[D[s]])) s--;
        if(s == 0){    // new lowest
            lis[i] = 1; D[1] = i;
        } else{
            lis[i] = s+1; D[s+1] = i; p[i] = D[s];
            if(lis[mdx] < lis[i])   mdx = i;
        }
    }

    int max = lis[mdx];
    
    stack<int> oo;
    
    while(mdx != p[mdx]){
        oo.push(mdx);
        mdx = p[mdx];
    }
    oo.push(mdx);   // the resulting mdx
    

    cout << max << endl;
    cout << "-" << endl;
    while(!oo.empty()){  cout << arr[oo.top()] << endl; oo.pop();}
    

    return 0;
}
