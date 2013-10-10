#include <iostream>
#include <vector>
#include <string>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#include <set>
#include <stack>
#include <map>
#include <sstream>

#define MAX 2000000000

using namespace std;

typedef pair<int,int>   ii;

int main(){
    string buf;
    while(getline(cin,buf)){
        stack<int> s;
        stack<int> w;
        int cur = MAX;
        int continuousPop = 0;
        istringstream in(buf);

        int n;
        bool fine = true;
        while(in >> n){
            if( n < 0){
                n = -n;
                s.push(n);

                if(continuousPop){
                    n += w.top();
                    w.pop();
                    continuousPop = 0;
                }
                w.push(n);
            } else{
                if(s.empty() || s.top() != n){
                    fine = false; break;
                }

                if(continuousPop){
                    if(s.top() <= w.top()){
                        fine = false; break;
                    }
                    w.pop();
                }
                s.pop();
                continuousPop++;
            }
        }
        if(!s.empty())  fine = false;
        if(fine) cout << ":-) Matrioshka!" << endl;
        else cout << ":-( Try again." << endl;
    }

    return 0;
}
