/*
Problem ID: 341
Solver: songyy
Start Time: 2011-4-5 9:10:02 
End Time:
Time Spent:
*/


#define INF 10000000
#include <iostream>
#include <stdio.h>
#include <vector>

using namespace std;

int p[100][100];

void backTrack(int u,int v){
	if(p[u][v]!=u)	backTrack(u,p[u][v]);
	printf(" %d",p[u][v] +1);
}

int main(){
	
//	freopen("341_in.txt","r",stdin);
	
	int N,u,v,t;
	int counter = 1;
	
	cin >> N;
	while(N!=0){
	//	printf("N=%d\n",N);
		int graph[N][N];
		
		for(int i=0;i<N;i++){
			p[i][i] = i;
		}
		
		for(int i=0;i<N;i++){
			for(int j=0;j<N;j++){
				graph[i][j] = (i==j)?0:INF;
			}
		}
		
		for(int i=0;i<N;i++){
			cin >> u;
			for(int j=0;j<u;j++){
				cin >> v >> t;
				graph[i][v-1] = t;
				p[i][v-1] = i;
			}
		}
		
		// Floyd Warshall's
		for(int k=0;k<N;k++){
			for(int i=0;i<N;i++){
				for(int j=0;j<N;j++){
					if(graph[i][j] > graph[i][k]+graph[k][j]){
						p[i][j] = p[k][j];
						graph[i][j] = graph[i][k]+graph[k][j];
					}
				}
			}
		}
		
		cin >> u >> v;
		u--;v--;
		
		printf("Case %d: Path =",counter++);
		backTrack(u,v);
		printf(" %d; %d second delay\n",v+1,graph[u][v]);

		
	/*	// for test only		
		printf("----------------------\n");
		for(int i=0;i<N;i++){
			for(int j=0;j<N;j++){
				printf("%8d ",graph[i][j]);
			}
			printf("\n");
		}
	*/
		
		cin >> N;
	}

//	while(1);
	return 0;
}
