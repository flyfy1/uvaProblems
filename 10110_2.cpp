/*
Problem ID: 10110
Solver: songyy
Start Time: 
End Time:
Time Spent: This is a much cleaner version, but solved the problem exactly.
*/

#include <iostream>
#include <stdio.h>
#include <vector>
#include <string.h>
#include <math.h>

using namespace std;

int main(){
//	freopen("10110.in","r",stdin);
	unsigned long n;
	
	while(cin >> n, n!= 0){
		unsigned long m = (unsigned long)(sqrt(n) + 0.1);
		if(m*m == n){
			cout << "yes" << endl;
		} else{
			cout << "no" << endl;
		}
	}
	
//	while(1);
//	system("Pause");
	return 0;
}
