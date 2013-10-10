/*
Problem ID: 10879
Solver: songyy
Start Time: 2011��8��6��8:13:19 
End Time: 2011��8��6��8:24:13 
Time Spent:10 min 
*/

#include <iostream>
#include <stdio.h>
#include <vector>
#include <string.h>
#include <math.h>

using namespace std;

/**
 * for a given integer a, factorize it.
 */
int factorize(long a){
	
}

int main(){
//	freopen("10879.in","r",stdin);
	
	int N;
	cin >> N;	// n test cases
	
	for(int i=0;i<N;i++){
		long t;
		cin >> t;
		
		int res[2] = {0,0}; int startIndex = 0;
		for(int testNum = 2; testNum < t && startIndex < 2 ; testNum++){
			if(t % testNum == 0){
				res[startIndex] = testNum;
				startIndex ++;
			}
		}
		
		printf("Case #%d: %d = %d * %d = %d * %d\n",i+1,t,res[0],t/res[0],
			res[1],t/res[1]);
	}
	
	return 0;
}
