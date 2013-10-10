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
typedef vector<int>     vi;
typedef vector<ii>      vii;

unsigned C;
vi ww;

int make(){
    for(int i=0;i<ww.size();i++){
        for(int j=i+1;j<ww.size();j++){
            if( ((C/ww[i])%ww.size()) == ((C/ww[j])%ww.size())){
                C = min( (C/ww[i] + 1) * ww[i],(C/ww[j] + 1) * ww[j]);
                return 1;
            }
        }
    }
    return 0;
}

int main(){
    string buf;
    string word;
    while(getline(cin,buf)){
        istringstream in(buf);
        ww = vi();
        while(in >> word){
            int s = 0;
            int base = 1;
            for(int i=word.size() - 1;i>=0;i--){
                s += (word[i] - 'a' + 1) * base;
                base <<= 5;
            }
            ww.push_back(s);
        }
        C = (1<<30) - 1;
        for(int i=0;i<ww.size();i++)    if(ww[i] < C) C = ww[i];
        while(make());
        cout << buf << endl << C << endl << endl;
    }

    return 0;
}
