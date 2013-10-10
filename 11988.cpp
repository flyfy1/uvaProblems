#include <iostream>
#include <list>
#include <string>
#include <cstdio>

using namespace std;

int main(){
    list<char> l;
    list<char>::iterator it;
    string buf;

    while(getline(cin,buf)){
        l.clear();
        it = l.begin();
        for(int i=0;i<buf.length();i++){
            if(buf[i] == '[')   it = l.begin();
            else if(buf[i] == ']')  it = l.end();
            else l.insert(it,buf[i]);
        }

        for(it = l.begin();it!= l.end(); it++){
            putchar(*it);
        }
        cout << endl;
    }

}
