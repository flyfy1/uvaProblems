/*
Problem ID: 10189
Solver: songyy
Start Time: 22/01/11 20:21
End Time: 	22/01/11 20:44
Time Spent:
*/

#include <iostream>
#include <string>

using namespace std;

char mine[110][110];
int out[110][110];

int main(){
	int m,n,count=1;
	int i,j;
	char c;
	int xRange[8]={-1,0,1,-1,1,-1,0,1};
	int yRange[8]={-1,-1,-1,0,0,1,1,1};
	//freopen("test.txt","r",stdin);
	
	while(cin >> m >> n, m!=0 && n!=0){
		// inialization
		memset(mine,0,sizeof(mine));
		memset(out,0,sizeof(out));
		if(count!=1)	putchar('\n');
		// read the input
		for(i=1;i<=m;i++)	scanf("%s",mine[i]+1);
		
		// deal with data
		for(i=1;i<=m;i++){
			for(j=1;j<=n;j++) if(mine[i][j]=='*')	for(int k=0;k<8;k++)	out[i+xRange[k]][j+yRange[k]]++;
		}
		
		// output
		printf("Field #%d:\n",count++);
		for(i=1;i<=m;i++){
			for(j=1;j<=n;j++)	putchar(mine[i][j]=='*'?'*':(out[i][j]+'0'));
			putchar('\n');
		}
		
	}
//	while(1);
//	system("Pause");
	return 0;
}
