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

int m[22],lis[22],arr[22],p[22];
int N;

int main(){
    string buf;
    cin >> N;
    int t;
    for(int i=0;i<N;i++){
        cin >> t;
        m[i] = t-1;     // the rank of event i
    }
    bool cont = true;
    while(cont){
        for(int i=0;i<N;i++){
            if(!(cin >> t)){
                cont = false;
                break;
            }
            arr[t-1] = i;     // buidl table: event of the i'th pos
        }
        if(!cont)   break;

        for(int i=0;i<N;i++)    arr[i] = m[arr[i]]; // actual rank of the event on that position

        lis[0] = 1;p[0] = 0;
        for(int i=1;i<N;i++){
            lis[i] = 1;p[i] = i;
            for(int j=0;j<i;j++){
                if(arr[j] < arr[i] && lis[i] < lis[j] + 1){
                    lis[i] = lis[j] + 1;
                    p[i] = j;
                }
            }
        }

        int mid = 0;
        for(int i=1;i<N;i++)    if(lis[mid] < lis[i]){ mid = i;}
        int max= lis[mid];

        /*
        stack<int> oo;
        while(mid != p[mid]){
            oo.push(mid);
            mid = p[mid];
        }
        oo.push(mid);   // the resulting mid
        */

        cout << max << endl;
    }
    return 0;
}
