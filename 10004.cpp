/*
Problem ID: 10004
Solver: songyy
Start Time: 2011年8月10日0:04:46 
End Time: 2011年8月10日1:04:58 
Time Spent: 1h
 This is a standard quesiton testing on Graph and BFS. Two things here took me some time:
		1. I've check how to write the vector of vector in C++ (and also how to initialize)
		2. I've thought about how to implement the BFS. It's quite a time since CS2020.
*/

#include <iostream>
#include <stdio.h>
#include <vector>
#include <string.h>

using namespace std;

// map to be used -- edge list
vector< vector<int> > map(210);
int points[210];

bool bfs_check_helper(int start, int end, int count){
	// first check if the end point is checked
	if(points[end]!=0){
		if( (points[end] - points[start])%2 == 0){
			return false;
		} else{
			return true;
		}
	}
	
	// then mark the point
	points[end] = count;
//	cout << end << " = " << count << endl;
	
	// then iterate through all the unchecked points
	for(int i = 0; i<map[end].size(); i++){
		if(bfs_check_helper(end,map[end][i],count+1) == false){
			return false;
		}
	}
	
	// after all, all checked, return true
	return true;
}

bool bfs_check(int a,int count){	// a is the starting index
	// first mark a
	points[a] = count;
	
	for(int i = 0;i < map[a].size(); i++){
		if(bfs_check_helper(a,map[a][i],count+1) == false){
			return false;
		}
	}
	
	// after all, all checked, return true
	return true;
}


int main(){
//	freopen("10004.in","r",stdin);
	
	int n,e;	// n points, e edges
	int a,b;	// for building the edge array
	
	// read input
 	while(cin >> n, n!= 0){
		cin >> e;
		
		for(int i=0;i<n;i++){
			map[i].clear();
		}
		
		for(int i = 0; i<e; i++){
			cin >> a >> b;
			map[a].push_back(b);
			map[b].push_back(a);
		}
		
		// check results
//		for(int i = 0; i < n; i++){
//			for(int j = 0; j<map[i].size(); j++){
//				cout << map[i][j] << " ";
//			}
//			cout << endl;
//		}
		
		
	 	// if # of edge is just one less than # of points, pass
//	 	if(e == n-1){
//			cout << "BICOLORABLE." << endl;
//			continue;
//		}
		
		// use BFS to check if there're graph oddly linked (meaning, for starting # a and 
		// ending # b, (a - b) % 2 == 1 --> then cannot be bicoloured)
		
		// first initialize the points; 0 means unvisited
		
		memset(points,0,210 * sizeof(int));
		
		if(bfs_check(a,1)){	// starting from the last input integer, and count form 1
			cout << "BICOLORABLE." << endl;
		} else{
			// on failure
			cout << "NOT BICOLORABLE." << endl;			
		}
	}
 	
//	while(1);
	return 0;
}
