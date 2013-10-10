/*
Problem ID: 10130
Solver: songyy
Start Time: 2011-4-10 10:08:29 
End Time:
Time Spent:
*/

#include <iostream>
#include <stdio.h>
#include <vector>
#include <string.h>
#include <string>

using namespace std;

int memo[1010][35];
int price[1010],weight[1010];

int N,MW;

int cal(int n, int limit){
	if(memo[n][limit]!=0)	return memo[n][limit];
	if(n==0){
		if(limit < weight[0])	return 0;
		else return price[0];
	}
	
	return 1;	
}

int main(){
	freopen("10130_in.txt","r",stdin);
	
	int TC;
	int NP;
	int UL;
	
	cin >> TC;
	
	while(TC--){
		cin >> N;
		for(int i=0;i<N;i++){
			cin >> price[i] >> weight[i];
		}
		
		int res = 0;
		
		memset(memo,0,sizeof(memo));
		
		cin >> NP;
		while(NP--){
			cin >> UL;
			res+= cal(N-1,UL);
		}
		
		cout << res << endl;
	}
	
    while(1);
	return 0;
}
