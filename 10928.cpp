/*
Problem ID: 10928
Solver: songyy
Start Time: 2011Äê3ÔÂ18ÈÕ12:12:34 
End Time:
Time Spent:
*/

#include <iostream>
#include <string.h>
#include <stdio.h>

using namespace std;

int main(){
	//freopen("in.txt","r",stdin);
	
	int TC,P;
	int t;
	
	cin >> TC;
	
	while(TC--){
		cin >> P;
		int counter[P+1];
		int marked[P+1];
		memset(counter,0,sizeof(counter));
		
		int m = 2;
		
		for(int u=1;u<=P;u++){
			cin >> t;

			memset(marked,0,sizeof(marked));
			counter[u]++;
			marked[u] = 1;
			while(getchar()!='\n'){
				cout << t << endl;
				cin >> t;
				if(marked[t]==0){
					counter[u]++;
					marked[u]=1;
				}
			}
			
		}
		
		int min=100000;
		for(int i=1;i<=P;i++){
			if(counter[i]<min)	min = counter[i];
		}
		int first = 1;
		cout << "min: " << min << endl;
		for(int i=1;i<=P;i++){
			if(counter[i] == min){
				if(first){cout << i;first = 0;}
				else{
					cout << " " << i;
				}
			}
		}
		cout << endl;
	}
 	
// 	system("pause");
	return 0;
}
