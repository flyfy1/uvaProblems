/*
Problem ID: 499
Solver: songyy
Start Time: 15/01/11 21:54
End Time: 17/01/11 21:21
*/

#include <iostream>

using namespace std;

// translate the character into the position of the array fre[]
int switchC(char c){
	if(isupper(c))	return	(c - 'A');
	else return (26+c-'a');
}

char tellC(int pos){
	if(pos<26)	return ('A'+pos);
	else return ('a'+pos-26);
}

int main(){
	//freopen("in.txt","r",stdin);
	
	char c;
	int max=0;	// the maximum frecequencyed letter
	int empty = 1;
	
	int letter[26*2]={};	// even position is the lower case, odd is the upper case
	int i,pos;
	
	
	while(scanf("%c",&c)==1){
		if(c=='\n'){	// condition to output & reset
			// output
			if(!empty)	for(i=0;i<26*2;i++)	if(letter[i]==max)	putchar(tellC(i));
			if(!empty)	putchar(' ');
			printf("%d\n",max);
			
			// reset
			memset(letter,0,sizeof(letter));max=0;empty=1;
		}
		if(isalpha(c)){
			empty = 0;
			pos = switchC(c);
			letter[pos]++;
			if(letter[pos]>max)	max=letter[pos];
		}
		
	}

	return 0;
}
