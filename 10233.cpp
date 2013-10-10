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
#define PI 3.141592653589793

using namespace std;

typedef pair<int,int>   ii;
typedef vector<int>     vi;
typedef vector<ii>      vii;
typedef vector<vi>     vvi;
typedef vector<vii>    vvii;
typedef map<int,int>    mii;

typedef struct Point{
    double x; double y;
    Point(double _x,double _y){x = _x; y = _y;}
} Point;

double sqrt3h = sqrt(3)/2;
double h = sqrt(3)/3;

Point getPoint(long long n){
    n++;
    long long p = sqrt(n);
    if(p*p < n) p++;
    
    long long dif = n - (p-1)*(p-1);
    double x = (dif - p) / 2.0;
    double y = (p-1)*sqrt3h + ( (dif&1)?h:sqrt3h-h);
    return Point(x,y);
}

int main(){
    int a,b;
    while(cin >> a >> b){
        Point pa = getPoint(a);
        Point pb = getPoint(b);
        printf("%.3lf\n",hypot(pa.x-pb.x,pa.y-pb.y));
    }

    return 0;
}
