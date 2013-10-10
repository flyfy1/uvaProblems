/*
Problem ID: 11332
Solver: songyy
Start Time: 18/01/11 15:22
End Time: 18/01/11 15:31
Time Spent:
*/

#include <iostream>

using namespace std;

int g(long a){
	int sum=0; char temp[12];
	sprintf(temp,"%ld",a);
	for(int i=0;i<strlen(temp);i++){
		sum += temp[i]-'0';
	}
	if(sum/10)	return g(sum);
	else return sum;
}

int main(){
	long a;
	while(cin >> a,a!=0){
		cout << g(a) << endl;
	}

//	system("Pause");
	return 0;
}
