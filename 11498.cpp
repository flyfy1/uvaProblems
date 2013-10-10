/*
Problem ID: 11498
Solver: songyy
Start Time: 18/01/11 15:37	(went to the lecture halfway, and other things)
End Time:
Time Spent:
*/

#include <iostream>

using namespace std;

int main(){
//	freopen("in.txt","r",stdin);
	int K,M,N;
	int a,b,dec;
	char res[20];
	
	while(cin >> K,K!=0){
		cin >> M >> N;
		while(K--){
			cin >> a >> b;
/* For each test case in the input your program must print one line containing:

    * the word divisa (means border in Portuguese) if the residence is on one of
	*** the border lines (North-South or East-West);
    * NO (means NW in Portuguese) if the residence is in Northwestern Nlogonia;
    * NE if the residence is in Northeastern Nlogonia;
    * SE if the residence is in Southeastern Nlogonia;
    * SO (means SW in Portuguese) if the residence is in Southwestern Nlogonia. 
*/
			dec = 0;
			if(a<M)	dec+= 1;	// W
			else if(a==M) dec+=0x4;	// divisa
			if(b<N) dec+= 2;	// N
			else if(b==N && (dec&0x4)==0) dec+=0x4;
			
			switch(dec){
				case 0: printf("NE");break;
				case 1: printf("NO");break;
				case 2: printf("SE");break;
				case 3: printf("SO");break;
				default: printf("divisa");break;
			}
			putchar('\n');
		}
	}
		
//	system("Pause");
	return 0;
}
