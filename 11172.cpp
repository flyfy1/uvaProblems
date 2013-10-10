/*
Problem ID: 11172
Solver: songyy
Start Time: 18/01/11 15:17
End Time: 18/01/11 15:20
Time Spent: 3 min
*/

#include <iostream>

using namespace std;

char tellC(int a, int b){
	if(a>b)	return '>';
	else if(a<b)	return '<';
	else return '=';	
}

int main(){
//	freopen("in.txt","r",stdin);
	int TC,a,b;

	cin >> TC;

	while(TC--){
		cin >> a >> b;
		cout << tellC(a,b) << endl;
	}
	
//	system("Pause");
	return 0;
}
