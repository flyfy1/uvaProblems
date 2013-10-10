/*
Problem ID: 10946
Solver: songyy
Start Time: 2011年8月12日9:35:22 
End Time: 2011年8月12日9:57:43 
Time Spent: 22 min
 Spend some time thinking how to sort the result; in the end refered to my stl notes.
*/

#include <iostream>
#include <stdio.h>
#include <vector>
#include <string.h>
#include <algorithm>

using namespace std;

char map[60][60];
int m,n;

struct hole{
	char name;
	int size;
};

int flood_fill_count(int a, int b, char h){
	if(a >= m || b >= n || a < 0 || b < 0 || map[a][b]!= h){
		return 0;
	}
	map[a][b] = '.';	// mark as visited
	int size = 1;
	size += flood_fill_count(a,b-1,h);
	size += flood_fill_count(a,b+1,h);
	size += flood_fill_count(a+1,b,h);
	size += flood_fill_count(a-1,b,h);
	return size;
}

bool comp(struct hole a, struct hole b){
	if(a.size != b.size)	return (a.size > b.size);
	return (a.name < b.name);
}

int main(){
//	freopen("10946.in","r",stdin);
	string t;
	
	int prob_num = 0;
	vector<struct hole> res;

	while(cin >> m >> n, m!=0){
		prob_num++;
		getline(cin,t);
		
		res.clear();
		
		// build the map
		for(int i=0;i<m;i++){
			getline(cin,t);
			strcpy(map[i],t.c_str());
		}
		
		// flood fill
		for(int i=0;i<m;i++){
			for(int j=0;j<n;j++){
				if(map[i][j]!='.'){
					struct hole h;
					h.name = map[i][j];
					h.size = flood_fill_count(i,j,map[i][j]);
					res.push_back(h);
				}
			}
		}
		
		// sort and output the result
		sort(res.begin(),res.end(),comp);
		cout << "Problem " << prob_num << ":" << endl;
		for(int i=0;i<res.size();i++){
			cout << res[i].name << " " << res[i].size << endl;
		}
	}

//	while(1);
	return 0;
}
