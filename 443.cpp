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



int main(){
    set <double> H;
    H.insert(1);
    set <double> :: iterator it = H.begin();

    while( H.size() < 7000){
        H.insert( *it * 2);
        H.insert( *it * 3);
        H.insert( *it * 5);
        H.insert( *it * 7);
        *it++;
    }

    vector<double> v(H.begin(), H.end());
    char str[6];
    int n;
    while( cin >> n && n){
        if(n % 10 == 1 && (n / 10) % 10 != 1)   strcpy(str,"st");
        else if(n % 10 == 2 && (n / 10) % 10 != 1)  strcpy(str,"nd");
        else if(n % 10 == 3 && (n / 10) % 10 != 1)  strcpy(str,"rd");
        else strcpy(str,"th");

        printf("The %d%s humble number is %0.lf.\n",n,str,v[n - 1]);
    }

    return 0;
}
