/*
Problem ID:
Solver: songyy
Start Time: 2011年8月8日21:42:03 
End Time: 2011年8月8日22:26:02 
Time Spent:44 min
Mainly spent on thinking about how to do the diagonal sum, and how to do an area sum

The unclear thinking took me some time at first; and the 'val' is a smart fix of my
in-complete thinking
*/

#include <iostream>
#include <stdio.h>
#include <vector>
#include <string.h>

using namespace std;

int arr[100][100];	// the 2D array

int val(int i,int j){
	if(i < 0 || j < 0)	return 0;
	return arr[i][j];
}


int main(){
//	freopen("108.in","r",stdin);
	

	int n;
	
	// read in the numbers
	cin >> n;
	
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cin >> arr[i][j];
//			cout << arr[i][j] << " ";	// testing
		}
//		cout << endl;
	}
	
	
	for(int i=0; i< n; i++){
		for(int j=0;j<n;j++){
			// sum over the rows
			if(j > 0) arr[i][j] += arr[i][j-1];
		}
	}
	
	for(int i=0; i< n; i++){
		for(int j=0;j<n;j++){
			// sum over colums after over the rows
			if(i > 0) arr[i][j] += arr[i-1][j];
		}
	}
	
//	cout << "After that" << endl;
//	
//	for(int i=0; i< n; i++){
//		for(int j=0;j<n;j++){
//			cout << arr[i][j] << " ";
//		}
//		cout << endl;
//	}
	
	// i,j loop to find maximum sum (n^2) efficienfy
	int max_sum = -30000;	// no number would be smaller than this
//	int a = -1, b = -1, c = -1, d = -1;
	
	for(int i=0; i< n; i++){
		for(int j=0;j<n;j++){
			for(int k = i; k<n; k++){
				for(int l = j; l < n; l++){
					int sum = val(k,l) - val(i - 1,l) - val(k,j -1) + val(i-1,j-1);
					if(max_sum < sum){
						max_sum = sum;
//						a = i, b = j, c = k, d = l;
					}
				}
			}
		}
	}
	
	cout << max_sum << endl;
//	printf("i: %d, j: %d, k: %d, l: %d\n",a,b,c,d);
	
//	while(1);
	return 0;
}
