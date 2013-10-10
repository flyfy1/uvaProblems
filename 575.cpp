/*
Problem ID: 575
Solver: songyy
Start Time: 2011年8月5日11:34:01 
End Time: 2011年8月5日12:06:59 
Time Spent: 30 minutes  (this problem should be solved within 5 minutes for a skilled ACMer)
*/
#define MAXSIZE 40

#include <iostream>
#include <stdio.h>
#include <vector>
#include <string.h>

using namespace std;

int main(){
//	freopen("575.in","r",stdin);
	
	// initialization
	char instr[MAXSIZE];memset(instr,95,MAXSIZE);	
	
	// read a line, see whether it's 0
	while(cin >> instr){
		if(instr[0] == '0') break;
		int numOfBits = strlen(instr);
		
		// transform to binary, calculate
		long binaryBase = 2, sum = 0;
		for(int i=numOfBits - 1; i>=0;i--){
			sum += (binaryBase - 1) * ( instr[i] - '0');
			binaryBase <<= 1;
		}
		
		cout << sum << endl;
	}
	
	return 0;
}
