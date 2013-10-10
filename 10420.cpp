/*
Problem ID: 10420
Solver: songyy
Start Time: 17/01/11 21:28
End Time: 17/01/11 23:11
Time Spent:
*/

#include <iostream>

using namespace std;

int main(){
	
//	freopen("in.txt","r",stdin);
	
	int TC;
	
	char countries[2000][75]={},temp[75];
	int num=0;
	int beauties[2000]={};	// the position of the country name is the value
	
	int i,j,t;
	
	cin >> TC;
	while(TC--){
		scanf("%s",temp);while(getchar()!='\n');
		
		for(i=0;i<num;i++)	if(strcmp(countries[i],temp)==0)	break;
		if(i==num){	
			strcpy(countries[num], temp);
			beauties[num]=1;
			num++;
		}	else{
			beauties[i]++;
		}
	}
	
	// sort : I use insertion sort here...
	for(i=1;i<num;i++){
		strcpy(temp,countries[i]);t=beauties[i];	// store
		for(j=i-1;(j>=0)&&(strcmp(countries[j],temp)>0);j--){	// move the data
			strcpy(countries[j+1],countries[j]);	beauties[j+1] = beauties[j];
		}
		j++;
		strcpy(countries[j],temp);beauties[j]=t;	// after care
	}
	
	// output
	for(int i=0;i<num;i++){
		printf("%s %d\n",countries[i],beauties[i]);
	}
	
//	while(1);
//	system("Pause");
	return 0;
}
