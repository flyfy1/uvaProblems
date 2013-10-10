/*
Problem ID: 11559
Solver: songyy
Start Time:  2012-1-1 16:39:49
End Time:    2012-1-1 17:01:32
Time Spent:  22 min
*/

#include <iostream>
#include <cstdio>

using namespace std;

int main(){
//	freopen("11559.in","r",stdin);

    int n,b,h,w;
    int p,a;

    while(cin >> n >> b >> h >> w){
        int res = -1;
        for(int i =0;i<h;i++){
            cin >> p;
            for(int j=0;j<w;j++){
                cin >> a;
                if( (a >= n) && (n*p <= b) && ( ((res != -1) && (res > n*p)) || (res == -1) ) ){
                    res = n * p;
                }
            }
        }

        if(res == -1)   cout << "stay home" << endl;
        else cout << res << endl;
    }

	return 0;
}
