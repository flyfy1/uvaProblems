/*
Problem ID: 11044
Solver: songyy
Start Time: 18/01/11 15:10
End Time: 18/01/11 15:16
Time Spent: 6 min
*/

#include <iostream>

using namespace std;

int main(){
//	freopen("in.txt","r",stdin);
	int TC,m,n;
	
	cin >> TC;
	
	while(TC--){
		cin >> m >> n;
		cout << (m/3)*(n/3) << endl;	
	}
	
	//system("Pause");
	return 0;
}
