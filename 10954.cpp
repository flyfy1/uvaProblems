#include <iostream>
#include <vector>
#include <string>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;

int main(){
//    freopen("10954.in","r",stdin);
    int n;
    int t;
    while(cin >> n, n){
        priority_queue<int, vector<int>,greater<int> > pq;
        int sum = 0;

        for(int i=0;i<n;i++){
            cin >> t;
            pq.push(t);
        }
        while(pq.size() > 1){
            t = pq.top();
            pq.pop();
            t += pq.top();
            pq.pop();

            sum += t;
            pq.push(t);
        }
        cout << sum << endl;

        // then try finding the sum
    }
}
