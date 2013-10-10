/*
Problem ID: 10279
Solver: songyy
Start Time: 2011年8月12日10:04:26 
End Time: 2011年8月12日10:25:23 (got the correct code)
	then: 2011年8月12日10:43:15	(got ACed) 
Time Spent: 20min + 20min = 40 min.
	Didn't do well in this problem because that.. I got sloppy when I was about 
	to output the result -- the problem says that "put a blank line between two 
	consecutive cases", but I put an extra blank line at the end of the output
	(where there's no more cases), and assuming this would be ignored.
	
	Simply becasae of this, I've wasted 15 minutes (plus, I've already made 
	similar mistakes before, which had taken me lots of time.)
*/

#include <iostream>
#include <stdio.h>
#include <vector>
#include <string.h>
#include <algorithm>

using namespace std;

char map[12][12];
int res[12][12];
int n;

void adder(int i,int j){
	if(i>=n || j>=n || i<0 || j<0){
		return;
	}
	res[i][j]++;
}

int main(){
//	freopen("10279.in","r",stdin);
 	
 	int TC;
	bool first = true;
 	string t;
 	
 	cin >> TC;
 	
 	while(TC--){
		cin >> n;
		getline(cin,t);
		
		if(first){
			first = false;
		} else{
			putchar('\n');
		}
		
		for(int i=0;i<n;i++){
			getline(cin,t);
			strcpy(map[i],t.c_str());
		}
		
		// build the map then
		memset(res,0,sizeof(res));
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				if(map[i][j] == '*'){
					res[i][j] = 9;
					adder(i+1,j+1);
					adder(i+1,j);
					adder(i+1,j-1);
					adder(i,j+1);
					adder(i,j-1);
					adder(i-1,j+1);
					adder(i-1,j-1);
					adder(i-1,j);
				}
			}
		}
		
		bool bomb = false;
		
		// then read the set for output
		for(int i=0;i<n;i++){
			getline(cin,t);
			strcpy(map[i],t.c_str());
			for(int j=0;j<n && !bomb;j++){
				if(map[i][j] == 'x' && res[i][j] >= 9){
					bomb = true;
				}
			}
		}
		
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				if(bomb && res[i][j]>=9){
					putchar('*');
				} else if(map[i][j]=='x'){
					putchar(res[i][j]+'0');
				} else{
					putchar('.');
				}
			}
			putchar('\n');
		}
	}
	
//	while(1);
	return 0;
}
