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

bool isLeapYear(long long y){
    return (y % 100 != 0 && y % 4 == 0) || (y % 400 == 0);
}
bool isHuluFest(long long y){
    return (y % 15 == 0);
}
bool isBuluFest(long long y){
    return isLeapYear(y) && (y % 55 == 0);
}

int main(){
    bool first = true;
    long long y;
    while(cin >> y){
        if(first)   first = false;
        else    putchar('\n');

        bool ordYear = true;
        if(isLeapYear(y)){
            ordYear = false;
            cout << "This is leap year." << endl;
        }
        if(isHuluFest(y)){
            ordYear = false;
            cout << "This is huluculu festival year." << endl;
        }
        if(isBuluFest(y)){
            ordYear = false;
            cout << "This is bulukulu festival year." << endl;
        }
        if(ordYear){
            cout << "This is an ordinary year." << endl;
        }
    }

    return 0;
}
