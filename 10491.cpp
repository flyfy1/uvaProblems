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
    double ncow,ncar,nshow;

    while( cin >> ncow >> ncar >> nshow){
        double t = ncow + ncar;
        printf("%.5lf\n",ncar/t * (ncar-1)/(t-1-nshow) + ncow / t * ncar / (t - 1 - nshow));
    }

    return 0;
}
