/*
Problem ID: 11340
Solver: songyy
Start Time: 2011-3-30 1:18:39 
End Time: 2011-3-30 1:38:04 
Time Spent: 20 min 
*/

#include <iostream>
#include <string.h>
#include <stdio.h>

using namespace std;

char str[10001];
int table[300];


int main(){
	int TC, K,M;
	long sum;
	double res;
	char c;
	int t;

// for test
//	freopen("in2.txt","r",stdin);
	
	scanf("%d%*c",&TC);
	
// for test
//	cout << TC;
	
	while(TC--){
		memset(table,0,sizeof(table));
		sum = 0;res = 0;
		
		scanf("%d%*c",&K);

// for test		
//		cout << ", K= " << K << endl;
		
		while(K--){
			scanf("%c%d%*c",&c,&t);
			table[c] = t;
		}
		
		scanf("%d%*c",&M);
		while(M--){
			fgets(str,10001,stdin);
			for(int i=0;i<strlen(str);i++){
				sum += table[str[i]];
			}
		}
		
		printf("%.2f$\n",((double)sum)/100);
	}
	
// for test
//	while(1);
	return 0;
}
