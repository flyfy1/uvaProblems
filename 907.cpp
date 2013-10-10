 /*
Problem ID: 907
Solver: songyy
Start Time:
End Time:
Time Spent:
*/

#include <iostream>
#include <stdio.h>
#include <vector>
#include <string.h>
#include <string>
#include <math.h>
#define INF 10000000


using namespace std;

int cost[700];
// the max of the journey (in a single day) up to k,n
int memo[700][400];// C,N
int C,N;


int cal(int k,int n){
	//return min(subcal(k,N,true,0),subcal(k,N,false,0));
	if(n<0)	return INF;
	if(k==0)	return 0;
	if(memo[k][n]!=0)	return memo[k][n];
	int minimum = cost[k];
	for(int i=1;i<k;i++){
		minimum = min(minimum,max(cal(i,n-1),cost[k]-cost[i]));
//		printf("min = %d, k=%d, i=%d\n",minimum,k,i);
	}
	memo[k][n] = minimum;
	return minimum;
}

int main(){
	freopen("907_in.txt","r",stdin);
	
	while(scanf("%d%d",&C,&N)!=EOF){
		for(int i=0;i<=C;i++){
			cin >> cost[i];
//			cout << cost[i] << endl;
		}
		
		// cumulative sum
		for(int i=0;i<C;i++){
			cost[i+1] += cost[i];
		}
		
//		for(int i=0;i<=C;i++){
//			cout << cost[i] << endl;
//		}
		
		
		memset(memo,0,sizeof(memo));
		
		cout << cal(C,N) << endl;
	}
	
	
	while(1);
	return 0;
}
