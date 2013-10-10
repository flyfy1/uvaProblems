/*
Problem ID: 10550
Solver: songyy
Start Time: 18/01/11 21:57
End Time: 18/01/11 23:13
Time Spent:
*/

#include <iostream>

using namespace std;

int clockwise(int ini, int a){
	if(a<ini)	a+=40;
	if(a==ini)	return 40;
	else return a-ini;
}

int anti_clockwise(int ini, int a){
	if(a==ini) return 40;
	else return 40 - clockwise(ini,a);
}

int main(){
//	freopen("in.txt","r",stdin);
	int ini,a,b,c,dif;	// dif: the difference of c,b
	
	
	while(cin >> ini >> a >> b >> c, ini!=0 || a!=0 || b!=0 || c!=0 ){
		int round1 = anti_clockwise(ini,a)*360/40,	// anti-clockwise actually
			round2 = clockwise(a,b)*360/40,	// clockwise actually
			round3 = anti_clockwise(b,c)*360/40;	// anti-clockwise
//		cout << round1 << ", " << round2 << ", " << round3 << endl;
		cout << round1 + round2 + round3 + 360*3 << endl;
	}
	
//	system("Pause");
	return 0;
}
