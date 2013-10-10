/*
Problem ID: 499
Solver: songyy
Start Time: 15/01/11 21:54
End Time:
Time Spent: 
*/

#include <iostream>

using namespace std;

// translate the character into the position of the array fre[]
int switchC(char c){
	if(c>='a' && c<='z')	return c-'a';
	else return c-'A'+26;
}

int tellC(int pos){
	if(pos<26)	return 'a'+pos;
	else return 'A' + pos-26;
}

// varify if char appeared in the array
int appeared(int letter_pos[],char c){
	return (letter_pos[switchC(c)]>0);
}

int main(){
	freopen("in.txt","r",stdin);
	
	char c;
	int max=1;	// the maximum frecequencyed letter
	int fre[26*2]={};	// to note down the frequency of each letter
	int letter_pos[26*2]={},map_back[26*2]={},num=0;	// the position of letter in fre[], the order of this order here is the letter order
	int i,order;
	
	while(scanf("%c",&c)==1){
		// in every test cases
		if(c=='\n'){
			for(i=0;i<num;i++)	if(fre[i]==max)	putchar(tellC(map_back[i]));
			cout << " " << max << endl;
			// re-initialize the data
			max = 1;memset(fre,0,sizeof(fre));memset(letter_pos,0,sizeof(letter_pos));num=0;memset(map_back,0,sizeof(map_back));
		}	else if(isalpha(c)){
			if(appeared(letter_pos,c)){
				order = letter_pos[switchC(c)];
				fre[order]++;
				if(fre[order]>max)	max++;
			}	else{	// create a new order
				order = switchC(c);
				letter_pos[order] = num;
				map_back[num]=order;
				fre[num++]++;
			}
			putchar(c);
		}
		//printf("max = %d", max);
	}
	while(1);
	system("Pause");
	return 0;
}
