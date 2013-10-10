/*
Problem ID:10943
Solver: songyy
Start Time: 
End Time:
Time Spent:
*/

#include <iostream>
#include <stdio.h>
#include <vector>
#include <string.h>

using namespace std;

int memo[110][110];

int p(int n, int k){
	if(memo[n][k])	return memo[n][k];
	int sum = 0;
	for(int i=0;i<=n;i++){
		sum += p(n-i,k-1);
		sum %= 1000000;
	}
	
	memo[n][k] = sum;
	return sum;
}

int main(){
	freopen("10943_in.txt","r",stdin);
	int n,k;
	memset(memo,0,sizeof(memo));
	memo[0][0] = 1;
	for(int i=1;i<=110;i++){
		memo[i][0] = 0;
		memo[i][1] = 1;
	}
	
	while(scanf("%d%d",&n,&k)!=EOF){
		if(n==0 && k==0)	break;
		cout << p(n,k) << endl;
	}
	while(1);
	return 0;
}
