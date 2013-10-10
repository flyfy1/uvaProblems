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
#include <cmath>

#define     M_SIZE      1100010

using namespace std;

typedef pair<int,int>   ii;

int arr[M_SIZE];
int arr2[M_SIZE];
long long cnt = 0;

void merge_count(int s,int e){
    // printf("s = %d, e = %d\n",s,e);
    if(s >= e)  return;
    if(s + 1 == e){
        if(arr[s] > arr[e]){
            int t = arr[s]; arr[s] = arr[e]; arr[e] = t;
            cnt++;
        }
        return;
    }
    int mid = (s + e) / 2;
    merge_count(s,mid);
    merge_count(mid+1,e);
    int cr = mid + 1;
    int ne = cr;
    int idx = 0;
    int ns = s;

    while(s <= mid && cr <= e){
        if(arr[s] <= arr[cr]){
            arr2[idx++] = arr[s++];
        } else{
            arr2[idx++] = arr[cr++];
            cnt += ne - s;
        }
    }
    while(s <= mid) arr2[idx++] = arr[s++];
    while(cr <= e)  arr2[idx++] = arr[cr++];

    // then I need to copy back these elements
    for(idx = 0;idx + ns <= e; idx++){
        arr[ns+idx] = arr2[idx];
    }
}

int main(){
    int n,t;
    while(scanf("%d",&n) != EOF){
        cnt = 0;
        for(int i=0;i<n;i++){
            scanf("%d",&arr[i]);
        }
        merge_count(0,n-1);
        printf("%lld\n",cnt);
    }

    return 0;
}
