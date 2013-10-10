/*
Problem ID: 10608
Solver: songyy
Start Time: 2011-3-17 15:48:34 
End Time: 2011-3-17 16:39:23 
Time Spent: 50 min (mainly on the implementation of union find)
*/

#include <iostream>

using namespace std;

// find the boss of u, and set the changes on the way, accordingly
int findBoss(int boss[], int u){
	int res = boss[u];
	
	// when u is not the boss of it self
	if(res!=u){
		res = findBoss(boss,boss[u]);
		boss[u] = res;
	}
	
	return res;
}

bool unionFind(int boss[],int u,int v){
	int uBoss = findBoss(boss, u);
	int vBoss = findBoss(boss, v);
	return uBoss==vBoss;
}



// return the boss setted to
// always set the boss to be the smaller one
int unionSet(int boss[], int u,int v){
	boss[findBoss(boss,u)] = boss[findBoss(boss,v)];
	return findBoss(boss,u);
}



int main(){
	int TC,N,M;
	
//	freopen("input.txt","r",stdin);
	
	cin >> TC;
	
	while(TC--){
		cin >> N >> M;

		int boss[N+1], knownSize[N+1];
		int maxPos = 1;
		
		// initialize the union find
		for(int i=1;i<=N;i++){
			boss[i] = i;
			knownSize[i] = 1;
		}
		
		// build the relationship for these N boss, M relationship
		while(M--){
			int u,v;

			cin >> u >> v;
			
			// new union added in
			if(!unionFind(boss,u,v)){
				int oldGroupKnown = knownSize[findBoss(boss,u)];
				unionSet(boss,u,v);
				int newIndex = findBoss(boss,u);
				knownSize[newIndex] += oldGroupKnown;
				if(knownSize[newIndex]>knownSize[maxPos])	maxPos = newIndex;
			}
		}
		
		cout << knownSize[maxPos] << endl;
	}
	
	/* for test union find
	freopen("test.txt","r",stdin);

	cin >> N >> M;
	int boss[N], knownSize[N];
	
	// initialize the union find
	for(int i=1;i<=N;i++){
		boss[i] = i;
		knownSize[i] = 1;
	}
	
	while(M--){
		int u,v;
		cin >> u >> v;
		unionSet(boss,u,v);
	}
	
	cout << findBoss(boss,5);*/
	
//	system("Pause");
//	while(1);
	return 0;
}
