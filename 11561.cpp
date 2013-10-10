/*
Problem ID: 11561
Solver: songyy
Start Time: 2011年8月10日21:56:19 
End Time: 2011年8月10日22:21:20 
Time Spent:25 min. Hopefully when I'm more mature at this, I'd be able to do it in less time.
*/

#include <iostream>
#include <stdio.h>
#include <vector>
#include <string.h>
#include <string>

using namespace std;

int m,n;
char map[60][60];

bool check_safe(int i, int j){
	if(map[i][j+1] == 'T') return false;
	if(map[i+1][j] == 'T') return false;
	if(map[i-1][j] == 'T') return false;
	if(map[i][j-1] == 'T') return false;
	return true;
}

int flood_fill_find(int p, int q){
	if(map[p][q] == '#' || map[p][q] == 'T') return 0;
	int sum = 0;
	switch(map[p][q]){
		case '#': 
		case 'T': return 0;
		case 'G': sum++;
		case '.':
		case 'P': 
			map[p][q] = '#';
			// check if it's save
			if(!check_safe(p,q))	return sum;
			sum += flood_fill_find(p,q + 1);
			sum += flood_fill_find(p + 1,q);
			sum += flood_fill_find(p,q - 1);
			sum += flood_fill_find(p - 1,q);
			return sum;
	}
}

int main(){
//	freopen("11561.in","r",stdin);
	string a;
	
	while(cin >> m >> n){
		getline(cin,a);
		for(int i = 0;i<n;i++){
			getline(cin,a);
			strcpy(map[i],a.c_str());
//			cout << map[i] << endl;
		}
		
		// find the p
		int p,q;
		for(int i=0;i<n;i++){
			for(int j=0;j<m;j++){
				if(map[i][j] == 'P'){
					p = i; q = j;
					goto l;
				}
			}
		}
		
		l:
			cout << flood_fill_find(p,q) << endl;
		// then flood fill
	}

//	while(1);
	return 0;
}
