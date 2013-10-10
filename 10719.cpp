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
#include <list>
#include <cmath>

using namespace std;

typedef pair<int,int>   ii;
typedef vector<int>     vi;
typedef vector<ii>      vii;
typedef vector<vi>     vvi;
typedef vector<vii>    vvii;
typedef map<int,int>    mii;


int main(){
    long long k;
    bool first = 1;
    while(cin >> k){

        string buf;
        getline(cin,buf);
        getline(cin,buf);

        istringstream in(buf);
        vector<long long> A;
        long long t;
        while(in >> t){
            A.push_back(t);
        }
        int n = A.size() - 1;
        vector<long long> C(n);
        for(int i=0;i<A.size()-1;i++){
            C[i] = A[i];
            A[i+1] += k*A[i];
        }
        int idx = 0;
        printf("q(x):");
        for(int i=0;i<C.size();i++){
            printf(" %lld",C[i]);
        }
        putchar('\n');
        printf("r = %lld\n\n",A[n]);

    }

    return 0;
}
