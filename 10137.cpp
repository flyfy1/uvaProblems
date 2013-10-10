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

int n;
int m[1001];

int main(){
    while(cin >> n,n){
        double sum = 0;
        for(int i=0;i<n;i++){
            double t;
            cin >> t;
            m[i] = round(t*100);
            sum += m[i];
        }
        double avg = sum / n;
        sum = 0;
        for(int i=0;i<n;i++){
            sum += abs(avg - m[i]);
        }
        sum /= 2;
        int res = round(sum);
        printf("$%d.%02d\n",res/100,res%100);
    }
    return 0;
}
