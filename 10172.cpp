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

int main(){
    int N,S,Q,TC;
    scanf("%d",&TC);
    while(TC--){
        scanf("%d%d%d",&N,&S,&Q);
        queue<int> q[N];
        stack<int> car;
        int t,c;
        int count = 0;
        for(int i=0;i<N;i++){
            scanf("%d",&c);
            // output the scanned info
            for(int j=0;j<c;j++){
                scanf("%d",&t);
                q[i].push(t);
                count++;
            }
        }

        int sum = 0;
        int city = 0;
        while(count){
            // unload the cargo into queue
            while(!car.empty() && q[city].size() < Q){
                if(car.top() != city+1){
                    q[city].push(car.top());
                } else  count--;
                car.pop();
                sum++;
            }
            if(!car.empty() && car.top() == city+1){
                car.pop();
                count--;sum++;
            }

            // get element from queue
            while(!q[city].empty() && car.size() < S){
                car.push(q[city].front());
                q[city].pop();
                sum++;
            }
            
            if(count){
                city = (city + 1) % N;
                sum += 2;   // move to the next city
            }
        }
        cout << sum << endl;
    }

    return 0;
}
