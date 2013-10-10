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


int main(){
    int N;
    char buf[20] = "";
    string bb;
    while(cin >> N){
        vector<string> v(N);
        getline(cin,bb);
        for(int i=0;i<N;i++)    getline(cin,v[i]);
        sort(v.begin(),v.end());
        int ml = 0;
        for(int i=0;i<N;i++)    if(ml < v[i].size())    ml = v[i].size();
        sprintf(buf,"%%-%ds",ml);
        int K = 62/(ml+2);
        int vs = N / K + (N%K != 0);
        vector< vector<string> > vo(K);
        cout << "------------------------------------------------------------" << endl;
        for(int i=0;i<vs;i++){
            for(int j=0;j<K-1 && j*vs + i < N;j++){
                printf(buf,v[j*vs + i].c_str());
                printf("  ");
            }
            int nN = (K-1) * vs + i;
            if(nN < N)  printf(buf,v[nN].c_str());
            putchar('\n');
        }
    }
    return 0;
}
