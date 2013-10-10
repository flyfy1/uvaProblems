#include <iostream>
using namespace std;



int main(){
	int r,c;
	char table[50][50];
	int visited[50][50];
	int i,j;
	
	int count;
	
	
	scanf("%d%d",&c,&r);
	for(i=0;i<r;i++){
		scanf("%s",table[i]);
	}
	
	// initialize
	memset(visited,0,sizeof(visited));
	count = 0;
	
	for(i=0;i<c;i++){
		for(j=0;j<r;j++){
			if(table[i][j]!='.'){
				// flood fill
				
			}
		}
	}
	
	
	
    system("Pause");
    return 0;
}
