/*
Problem ID: 11799
Solver: songyy
Start Time:  2012-1-1 17:03:58
End Time:    2012-1-1 17:10:20
Time Spent:  7 min
*/

#include <iostream>
#include <cstdio>

using namespace std;

int main(){
	//freopen("11799.in","r",stdin);
    int n,t;

    cin >> t;
    for(int i=0;i<t;i++){
        int max = -1;
        int s;

        cin >> n;
        for(int j=0;j<n;j++){
            cin >> s;
            if(max < s){
                max = s;
            }
        }

        cout << "Case " << i+1 << ": "  << max << endl;
    }

	return 0;
}
