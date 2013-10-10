/*
Problem ID:
Solver: songyy
Start Time: 01/02/11 20:52
End Time: 01/02/11 21:03
Time Spent:
*/

#include <iostream>

using namespace std;

int a[1000];

int main(){
	int TC;
	int n;
	double avg,sum,count;
	int i,j,t;
	
	
	cin >> TC;
	while(TC--){
		cin >> n;
		sum=0;
		for(i=0;i<n;i++){
			cin >> a[i];
			sum+=a[i];
		}
		avg = sum/n;
		
		count=0;
		for(i=0;i<n;i++){
			if(a[i]>avg)	count++;
		}
		printf("%.3lf",(count)/n*100);
		putchar('%');putchar('\n');
	}

//	system("Pause");
	return 0;
}
