/*
Problem ID: 10110
Solver: songyy
Start Time: 2011年8月10日13:42:04 
End Time: 2011年8月10日14:56:17 
Time Spent: 1h 15min - 15 min = 1h. (half way talked with mum and went to see a friend)
  It doesn't worth this amount of time for this kind of simple problem...
  I wrote a small piece of factorization code, and turned out to be time-out
  
  Then I found the patterns of the correct answers -- all square numbers.
  Then I tried with an code testing whether it's a square number or not-- and got
  WA; I searched over the internet, found a pretty good explaination about it.
  
  Then I realized how silly I was when at the start, I didn't think deep into the
  problem and starts coding immediately.
  
  This is the source of doing unimportant things -- never learnt the problem well.
*/

#include <iostream>
#include <stdio.h>
#include <vector>
#include <string.h>
#include <math.h>

using namespace std;

/**
 * Return the smallest factor starting from start
 * return a is prime number (at least non-dividable by start ~ a - 1)
 */
long factorize(long a, long start){
	long i;
	for(i = start; i <= ceil(sqrt(a)); i++){
		if((a % i) == 0){
			return i;
		}
	}
//	cout << "before return: " << i << endl;
	
	return a;	// no match; return a itself
}


int main(){
//	freopen("10110.in","r",stdin);
	
	long n; vector<int> factors;
	
	while(cin >> n, n != 0){
		factors.clear();
		long n_f = 0;				// # of factor
		long s_f = 2;			// starting factor
		long c_f = factorize(n,s_f);	// current factor

//					cout << "c_f: " << c_f << ", s_f: " << s_f << endl;
		
		while(n!=1){
			n = n/c_f; s_f = c_f;	// first new integer
			
			// at first to insert a new one
			factors.push_back(1); n_f++;
			c_f = factorize(n,s_f);
			

			
			while(c_f == s_f){
				n = n/c_f; factors[n_f -1]++;
				c_f = factorize(n,s_f);
			}
		}
		
		// output test
//		for(int i=0;i<factors.size();i++){
//			cout << factors[i] << " ";
//		}
//		cout << endl;

		// then test result; it would be one only when # of factors is odd
		int t_f = 1;
		for(int i=0;i<factors.size();i++){
			t_f *= (factors[i] + 1);
		}
		
		if(t_f&1){	// odd
			cout << "yes" << endl;
		} else{
			cout << "no" << endl;
		}
	}
	
//	while(1);
	return 0;
}
