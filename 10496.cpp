/*
Problem ID: 10496
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

int dis(int a[2],int b[2]){
	return abs(a[0]-b[0]) + abs(a[1]-b[1]);
}

int main(){
	freopen("10496_in.txt","r",stdin);
	
	int TC, R,C;
	int sX, sY;
	int E;
	
	int graph[20][20];
	
	cin >> TC;
	
	while(TC--){
		cin >> R >> C;
		cin >> sX >> sY;
		cin >> E;
		int point[E+1][2];
		point[0][0] = sX; point[0][1] = sY;
		for(int i=1;i<=E;i++){
			cin >> point[i][0];
			cin >> point[i][1];
		}
	
		// build the graph		
		for(int i=0;i<=E;i++){
			for(int j=i+1;j<=E;j++){
				graph[j][i] = graph[i][j] = dis(point[i],point[j]);
			}
		}
		for(int i=0;i<=E;i++) graph[i][i] = 0;
		
//		int cost[]
		// bellman ford's
		for(int i=0;i<=E;i++){
			for(int j=0;j<=E;j++){
				for()
			}
		}
	}
 	
 	cout << TC;
	while(1);
	return 0;
}
