/*
Problem ID:	594
Solver: songyy
Start Time: 2011年1月17日19:18:29 
End Time: 2011年1月17日20:05:33 
Time Spent:
*/

#include <iostream>

using namespace std;

long converts(long a){
    int res=0;

	for(int i=0;i<4;i++){
        res<<=8; 
        res += a&255;
        a>>=8;
    }
	return res;
}

int main(){
	long in;
	
	while(scanf("%ld",&in)==1){
		cout << in << " converts to " << converts(in) << endl;
	}

	return 0;
}
