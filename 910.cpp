/*
Problem ID: 910
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

using namespace std;

int edge0[30], edge1[30], isDes[30];
int memo[30][31];

int cal(int u,int k){
	if(memo[u][k]!=-1)	return memo[u][k];
	
	if(k==0){
 		if(isDes[u]){
			memo[u][k] = 1;
		} else memo[u][k] = 0;
		return memo[u][k];
	}
	
	memo[u][k] = cal(edge0[u],k-1) + cal(edge1[u],k-1);
	
	return memo[u][k];
}

int main(){
	
//	freopen("910_in.txt","r",stdin);
	
	int N;
	char c0,c1,isD;
	int Q;
	
	while(scanf("%d%*c",&N)!=-1){
		memset(edge0,0,sizeof(edge0));
		memset(edge1,0,sizeof(edge1));
		memset(isDes,0,sizeof(isDes));
			
		for(int i=0;i<30;i++){
			for(int j=0;j<31;j++){
				memo[i][j] = -1;
			}
		}
		//memo[0][0] = 1;
		
		//printf("%d\n",N);
		for(int i=0;i<N;i++){
			scanf("%*c %c %c %c%*c",&c0,&c1,&isD);
			edge0[i] = c0 - 'A';
			edge1[i] = c1 - 'A';
			isDes[i] = (isD == 'x');
		}
		
		
		/*
		for(int i=0;i<N;i++){
			printf("%d, %d\n",edge0[i],edge1[1]);
		}*/
		
		cin >> Q;
		cout << cal(0,Q) << endl;
	}

//	while(1);
	return 0;
}
