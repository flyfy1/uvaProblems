/*
Problem ID: 10702
Solver: songyy
Start Time: 
End Time:
Time Spent:
*/

#include <iostream>
#include <stdio.h>
#include <vector>
#include <string.h>

#define INF 1000000

using namespace std;

int graph[100][100];
int memo[100][1000];
bool possibleEndings[100];
int C,S,E,T;

int cal(int u,int k){
	int temp = -INF;
	int sum  = -INF;
	
	if(memo[u][k]!=-1)	return memo[u][k];
	
	if(k==1){
		for(int i=0;i<C;i++){
			if(possibleEndings[i] == true){
				if(temp < graph[u][i]){
					temp = graph[u][i];
				}
			}
		}
		memo[u][k] = temp;
		return temp;
	}

	
	for(int i=0;i<C;i++){
		temp = cal(i,k-1);
		if(sum < temp + graph[u][i])	sum = temp + graph[u][i];
	}
	memo[u][k] = sum;
	return sum;
}

int main(){
//	freopen("10702_in.txt","r",stdin);
	
	int t;

	// C - # city, S - start city , E - end city, T - # of inter city travel
	
	cin >> C >> S >> E >> T;
	while(C||S||E||T){
//		printf("%d, %d, %d, %d\n",C,S,E,T);
//		while(1);
		
		// initialization
		memset(possibleEndings,0,sizeof(possibleEndings));
		for(int i=0;i<100;i++){
			for(int j=0;j<1000;j++){
				memo[i][j] = -1;
			}
		}	
		
		for(int i=0;i<C;i++){
			for(int j=0;j<C;j++){
				cin >> graph[i][j];
			}
		}
		
		for(int i=0;i<E;i++){
			cin >> t;
			possibleEndings[t-1] = true;
		}
		
		cout << cal(S-1,T) << endl;
		
		cin >> C >> S >> E >> T;
	}
	
//	while(1);
	return 0;
}
