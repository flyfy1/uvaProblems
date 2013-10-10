/*
Problem ID: 10783
Solver: songyy
Start Time: 18/01/11 14:51
End Time: 18/01/11 15:04
Time Spent: 15 min
*/

#include <iostream>

using namespace std;

int main(){
//	freopen("in.txt","r",stdin);
    int TC;
    int a,b;
    int i,n;
    
    cin >> TC;
    
    for(i=1;i<=TC;i++){
        cin >> a >> b;
        if(a%2==0)a++;
        if(b%2==0)b--;
        n=(b-a)/2;
        cout << "Case " << i << ": " << (a*(n+1)+n*(n+1)) << endl;
    }
    
//	system("Pause");
	return 0;
}
