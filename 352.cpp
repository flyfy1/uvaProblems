/*
Problem ID: 352
Solver: songyy
Start Time: 2011年8月11日10:09:03 
End Time:2011年8月11日10:24:54 
Time Spent: 15 min, I should be able to finish this in less time 
 This question is bugged -- when outputing number 0,1, singler form should be used.
*/

#include <iostream>
#include <stdio.h>
#include <vector>
#include <string.h>

using namespace std;

char arr[30][30];
int n;

// use hte map to do flood fill; return true if this place should be counted
bool flood_fill(int a,int b){
	// test if it's in the range, or visited
	if(a < 0 || b < 0 || a >= n || b >= n || arr[a][b] == '0'){
		return false;
	}
	
	if(arr[a][b] == '1'){
		arr[a][b] = '0';	// mark as visited first
		flood_fill(a,b+1);
		flood_fill(a,b-1);
		flood_fill(a+1,b);
		flood_fill(a-1,b);
		flood_fill(a+1,b+1);
		flood_fill(a+1,b-1);
		flood_fill(a-1,b+1);
		flood_fill(a-1,b-1);
	}
	return true;
}

int main(){
//	freopen("352.in","r",stdin);
	string a;
	int img_num = 0;
	
	while(cin >> n){
		getline(cin,a);
		img_num++;
		
		// build the map
		for(int i=0 ;i < n; i++){
			getline(cin,a);
			strcpy(arr[i],a.c_str());
		}
		
		int count = 0;
		for(int i=0; i<n; i++){
			for(int j=0;j<n;j++){
				if(flood_fill(i,j)){
					count ++;
				}
			}
		}
		
		printf("Image number %d contains %d war eagles.\n",img_num,count);
	}
	
	
	
//	while(1);
	return 0;
}
