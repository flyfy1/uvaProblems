#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#include <set>
#include <stack>
#include <map>

using namespace std;

typedef pair<int,int>   ii;

int main(){
    int t,N,n;
    string buf;
    while(scanf("%d",&N),N){
        getline(cin,buf);
        while(getline(cin,buf),buf[0] != '0'){
            istringstream in(buf);
            //cout << buf << endl;
            int n = 1;
            bool fine = true;
            stack<int> s;
            while(in >> t){
                while(t > n) s.push(n++);
                if(t == n)  n++;
                else if(t < n){
                    if(s.top() == t)    s.pop();
                    else{   fine = false;break;}
                }
            }
            printf("%s\n",fine?"Yes":"No");
        }
        putchar('\n');
    }
    return 0;
}
