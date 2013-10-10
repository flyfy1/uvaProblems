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
#define VAL 1000001

using namespace std;

typedef pair<int,int>   ii;
typedef vector<int>     vi;
typedef vector<ii>      vii;
typedef vector<vi>     vvi;
typedef vector<vii>    vvii;
typedef map<int,int>    mii;

vector<bool> tb(VAL,false);
set<int> fac;

int main(){
    for(int i=2;i<VAL;i++){
        if(tb[i])   continue;
        for(int j=2;j*i < VAL;j++){
            tb[i*j] = true;
        }
    }

    for(int i=3;i<VAL;i++)  if(!tb[i]) fac.insert(i);

    int n,prime;
    while(cin >> n,n){
        prime = -1;
        for(set<int>::iterator it = fac.begin(); it != fac.end(); it++){
            if(fac.count(n - *it)){
                prime = *it;break;
            }
        }
        if(prime != -1) printf("%d = %d + %d\n",n,prime,n-prime);
        else printf("Goldbach's conjecture is wrong.\n");
    }   

    return 0;
}
