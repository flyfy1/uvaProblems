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

typedef struct Tzolkin{
    int d,m,y;
    Tzolkin(int _d,int _m,int _y){
        d = _d; m = _m; y = _y;
    }
    Tzolkin(){};
} Tzolkin;

int haab2num(int day,int mon,int year){
    return year * 365 + mon * 20 + day;
}

Tzolkin num2Tzo(int num){
    Tzolkin r;int t = num % 260;
    r.y = num / 260;
    r.m = t % 13 + 1;
    r.d = t % 20;
    return r;
}

char TzolDay[20][10] = {
    "imix", "ik", "akbal", "kan", "chicchan", 
    "cimi", "manik", "lamat", "muluk", "ok",
    "chuen", "eb", "ben", "ix", "mem",
    "cib", "caban", "eznab", "canac", "ahau"
};

string HaabMon[19] = {
     "pop", "no", "zip", "zotz", "tzec",
     "xul", "yoxkin", "mol", "chen", "yax",
     "zac", "ceh", "mac", "kankin", "muan",
     "pax", "koyab", "cumhu","uayet"
};

int main(){
    map<string,int> haabMon2nmap;
    for(int i=0;i<19;i++){
        haabMon2nmap[HaabMon[i]] = i;
    }

    int tc,d,y;
    string ts,mons;
    cin >> tc;
    cout << tc << endl;
    while(tc--){
        cin >> d >> ts >> mons >> y;
        Tzolkin tzo = num2Tzo(haab2num(d,haabMon2nmap[mons],y));
        printf("%d %s %d\n",tzo.m,TzolDay[tzo.d],tzo.y);
    }

    return 0;
}
