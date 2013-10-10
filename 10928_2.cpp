/*
Problem ID: 10928
Solver: songyy
Start Time: 2011-3-29 23:52:11 
End Time:	2011-3-30 1:01:38 
Time Spent:
*/

#include <iostream>
#include <string>
#include <sstream>
#include <string.h>
#include <stdio.h>

using namespace std;

int counter[10000];

int main(){
	int TC,P,t;
	char str[10000];
	int first, min;
	int i;
//	freopen("in.txt","r",stdin);
	
	cin >> TC;
	
	while(TC--){
		cin >> P;
		
		int p = P;
		
		memset(counter,0,sizeof(counter));

		i=0;
		while(p!=0){
			fgets(str,9999,stdin);
		//	cout << "i: " << i << endl;
			istringstream str1(str);
			
			while(str1 >> t){
		 		counter[i]++;
			}
			
			if(counter[i]!=0){
				p--;
				i++;
			}
		}
		
		min = 99999;
		for(i=0;i<P;i++){
			if(min > counter[i]){
				min = counter[i];
			}
		}
		
		first = 1;
		for(i=0;i<P;i++){
			if(counter[i]==min){
				if(first){
					first = 0;
				} else{
					cout << " ";
				}
				cout << i+1;
			}
		}
		cout << endl;
	}
	
//	while(1);
//	system("Pause");
	return 0;
}
