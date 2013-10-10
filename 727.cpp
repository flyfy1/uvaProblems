#include <iostream>
#include <vector>
#include <string>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#include <set>
#include <stack>

using namespace std;

bool is_plus_minus(char c){
    return (c == '+' || c == '-');
}

bool is_mul_div(char c){
    return (c == '*' || c == '/');
}

int main(){
    freopen("727.in","r",stdin);
    int n;
    char c;
    char t;
    string buf;
    stack<char> s;

    scanf("%d\n",&n);
    bool first = true;

    while(n--){
        if(first){
            first = false;
        } else{
            putchar('\n');
        }
        while(getline(::cin,buf),buf!=""){
            c = buf[0];

            if(isdigit(c)){
                putchar(c);
            } else if(c == '(') {
                s.push(c);
            } else if(c == ')') {
                // pop until (
                while(s.top() != '('){
                    putchar(s.top());
                    s.pop();
                }
                s.pop();
            } else if(is_plus_minus(c)){
                while(!s.empty() && s.top() != '('){
                    putchar(s.top());
                    s.pop();
                }
                s.push(c);
            } else if(is_mul_div(c)){
                while(!s.empty() && is_mul_div(s.top())){
                    putchar(s.top());
                    s.pop();
                }
                s.push(c);
            }
        }

        while(!s.empty()){
            putchar(s.top());
            s.pop();
        }

        putchar('\n');
    }
}

