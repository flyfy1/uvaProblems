/*
Problem ID: 113
Solver: songyy
Start Time: 2011年8月7日11:22:07 
End Time: 2011年8月7日11:31:41 
Time Spent: 10 min, WA once
*/

#include <iostream>
#include <stdio.h>
#include <vector>
#include <string.h>
#include <cmath>

using namespace std;

int main(){
//	freopen("113.in","r",stdin);
	double n,p;
	while(cin >> n >> p){
//		cout << n << p << endl;
		int res = (int)(pow(p,1/n) + 0.2);
		cout << res << endl;
	}

//	while(1);
	return 0;
}
