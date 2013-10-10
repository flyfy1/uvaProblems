#include <iostream>
#include <vector>
#include <string>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#include <set>

#define DIFF ('a' - 'A')

using namespace std;



struct CompareFunction{
    bool operator()(const string &x, const string &y) const
    {
        for(int i=0;i<x.size();i++){
            if(tolower(x[i]) != tolower(y[i]))  return tolower(x[i]) < tolower(y[i]);
            else if(x[i] != y[i])   return x[i] < y[i];
        }
        return false;
    }
};

int main(){
    freopen("195.in","r",stdin);

    int tc;
    string str;
    set<string,CompareFunction > s;

    cin >> tc;
    while(tc--){
        s.clear();
        cin >> str;
        sort(str.begin(),str.end());
        do{
            s.insert(str);
        }while(next_permutation(str.begin(),str.end()));

        for(set<string>::iterator it = s.begin(); it!= s.end();it++){
            cout << *it << endl;
        }
    }
}
