/*
Problem ID: 482
Solver: songyy
Start Time: 2011-4-1 8:38:46 
End Time:
Time Spent:
*/

#include <iostream>
#include <string>
#include <sstream>
#include <string.h>
#include <stdio.h>
#include <vector>

using namespace std;


int main(){
//	freopen("in.txt","r",stdin);
	
	int TC;
	vector<int> order;
	int t;
	string s;
	char temp[100000]="";
	
	bool first = true;
	
	cin >> TC;
	while(TC--){		
		order.clear();
		
		strcpy(temp,"");
		while(strlen(temp)<=1) fgets(temp,100000,stdin);
		istringstream cin1(temp);
		while(cin1 >> t){
			order.push_back(t);
		}
		
		
		vector<string> str;

		strcpy(temp,"");
		while(strlen(temp)<=1) fgets(temp,100000,stdin);
		istringstream cin2(temp);
		while(cin2 >> s){
			if(s=="") continue;
			str.push_back(s);
		}
		
		string res[order.size()];
		for(int i=0;i<order.size();i++){
			res[order[i]-1] = str[i];
		}
		
		
		
		if(first){
			first = false;
		} else {
			cout << endl;
		}
		for(int i=0;i<order.size();i++){
			cout << res[i] << endl;
		}
		

		
		/*for(int i=0;i<str.size();i++){
			cout << str[i] << endl;
		}
		cout << str.size() << ", " << order.size();
		cout << endl;*/
	}
	
//	while(1);
	return 0;
}
