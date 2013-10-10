/*
Problem ID: 146
Solver: songyy
Start Time: 19/01/11 10:18
End Time: 19/01/11 10:35
Time Spent: 20min, mainly on learning "next_permutation"
*/

#include <iostream>
#include <algorithm>

using namespace std;

int main(){
//	freopen("in.txt","r",stdin);
	char a[52];bool dec;
	
	while(cin >> a, a[0]!='#'){
		dec = next_permutation(a,a+strlen(a));
		if(dec)	cout << a << endl;
		else cout << "No Successor" << endl;
	}
//	system("Pause");
	return 0;
}
