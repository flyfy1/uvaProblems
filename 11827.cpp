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

int gcd(int a,int b){
    while(b > 0){
        int r = a % b;
        a = b; b = r;
    }
    return a;
}

int arr[101];
int size = 0;

int main(){
    string buf;
    int tc;
    cin >> tc; getline(cin,buf);
    while(tc--){
        getline(cin,buf);
        size = 0;
        int t;
        istringstream in(buf);
        while(in >> t){
            arr[size++] = t;
        }
        
        int md = 1;
        for(int i=0;i<size;i++){
            for(int j=i+1;j<size;j++){
                int d = gcd(arr[i],arr[j]);
                md = max(md,d);
            }
        }
        cout << md << endl;
    }

    return 0;
}
