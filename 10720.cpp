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

int arr[10010];

int main(){
    int n;
    
    while(scanf("%d",&n),n){
        for(int i = 0;i<n;i++)  scanf("%d",&arr[i]);
        bool fine = true;
        int start = 0;
        while(start < n && fine){
            sort(arr,arr+n,greater<int>());
            
            if(arr[start] >= n - start){
                fine = false;
                break;
            }
            
            for(int i=1;i<=arr[start];i++){
                arr[start + i]--;
                if(arr[start + i] < 0){
                    fine = false;
                    break;
                }
            }
            start++;
        }
        if(fine)    printf("Possible\n");
        else        printf("Not possible\n");
    }

    return 0;
}
