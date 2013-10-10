/*
Problem ID: 579
Solver: songyy
Start Time: 2011年8月10日11:23:21 
End Time: 2011年8月10日11:51:50 
Time Spent: nearly 0.5h

This is a very easy problem which should have been done within 10 minutes at most.
I struggled over the output(because I made a wrong termination condition for the
while loop, and didn't recognize it for a while); in addition, I also made a wrong
assumption about the clock time -- I didn't think about the change of the clock 
angle when the minute hand is not pointing to 0.

Afterall it's just several lines of code.
*/

#include <iostream>
#include <stdio.h>
#include <vector>
#include <string.h>
#include <math.h>

using namespace std;

int main(){
//	freopen("579.in","r",stdin);
	
	int h,m;
	
	double a,b;
	
	while(scanf("%d:%d",&h,&m),(h!=0 || m!=0) ){
		// change the h to angle
		a = h * 360/12 + ((double)m)/2.0;
		b = m * 360/60;
		if(a == 360) a = 0;
		
		double diff = ((a-b)>0)?(a-b):(b-a);
		printf("%.3lf\n",min(diff,360-diff));
	}
	
//	while(1);
	return 0;
}
