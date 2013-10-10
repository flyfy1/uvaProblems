/*
Problem ID: 10038
Solver: songyy
Start Time: 21/01/11 00:58
End Time: 21/01/11 01:22
Time Spent:
*/

#include <iostream>
#include <string>
using namespace std;

int a[3000];

int abs(int diff){
	return (diff>0)?diff:(-diff);
}

int main(){
	int n,former,current,diff;
	int i;
	int dec;
	
	while(scanf("%d",&n)==1){
		memset(a,0,sizeof(a));
		dec=1;
		cin >> former; //printf("former = %d",former);
		for(i=1;i<n;i++){
			current = former;
			cin >> former;	//printf("i=%d\n",i);
			diff = abs(current-former);
			if(diff==0)	dec=0;
			else if(diff>=n){dec=0;}
			else if(a[diff]){dec=0;}
			else{a[diff]=1;}
		}
		
		
		if(dec)	cout << "Jolly" << endl;
		else cout << "Not jolly" << endl;
	}
	
	return 0;
}
