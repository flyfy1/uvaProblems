/*
Problem ID: 10008
Solver: songyy
Start Time: 2011年8月5日12:09:36 
End Time: 2011年8月5日12:43:38 
Time Spent: 35 minutes. chatted with Shubham for around 2 minutes in the middle;
	and also searched for string iterators, sort(though didn't use it) 
*/

#include <iostream>
#include <stdio.h>
#include <vector>
#include <string.h>

using namespace std;

int main(){
//	freopen("10008.in","r",stdin);
	
	// read # of lines
	int numOfLines = 0;
	cin >> numOfLines;
	int letterFrequency[26];
	memset(letterFrequency,0,26*sizeof(int));

	string line;
	getline(cin,line);	// eliminate the first line (cuz of the end of line character not parsed)
	
	for(int lineNum = 0; lineNum < numOfLines; lineNum++){
		string line;
		getline(cin,line);
		
		string::iterator lineChar;
		// read reach line, count the appearance of each later
		for(lineChar = line.begin(); lineChar != line.end(); lineChar++)
		{
		    char t = *lineChar;
		    if(isalpha(t)){
				t = toupper(t);
				letterFrequency[t - 'A']++;
//				printf("%c: index - %d, frequency: %d\n",t,t-'A',letterFrequency[t - 'A']);
			}
		}
	}

	// sort for output
	// loop through each leter
	while(1){
		// find the max
		int max = 0,maxIndex = -1;
		for(int i = 0; i<26;i++){
			if(letterFrequency[i]>0 && (max < letterFrequency[i])){
				max = letterFrequency[i]; maxIndex = i;
			}
		}
		
		// maxIndex didn't change, means all 0
		if(maxIndex == -1){
			break;
		}
		
		// output the this first
		printf("%c %d\n",maxIndex+'A',letterFrequency[maxIndex]);
		// then turn it to 0
		letterFrequency[maxIndex] = 0;
	}
	return 0;
}
