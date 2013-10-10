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

pair<int,int> tt[105];
char as[20],bs[20],buf[255];

int ts2int(char s[]){
    int h,m;
    sscanf(s,"%d%*c%d",&h,&m);
    return h*60 + m;
}

string int2ts(int t){
    char buf[10];
    sprintf(buf,"%02d:%02d",t/60,t%60);
    return string(buf);
}

string length2td(int d){
    char buf[100];
    if(d >= 60)  sprintf(buf,"%d hours and %d minutes.",d/60,d%60);
    else    sprintf(buf,"%d minutes.",d);
    return string(buf);
}

int main(){
    int n;
    int CC = 1;
    while(cin >> n){
        for(int i=0;i<n;i++){
            scanf("%s%s",as,bs);
            tt[i] = ii(ts2int(as),ts2int(bs));
            fgets(buf,255,stdin);
        }
        tt[n] = ii(18*60,18*60+1);

        sort(tt,tt+n+1);
        int m_l_start = 0,m_length = 0,last_end_time = 10*60,cidx = 0;
        while(true){
            while(cidx <= n && last_end_time > tt[cidx].first)   cidx++;
            if(cidx > n)   break;
            if(tt[cidx].first - last_end_time > m_length){
                m_length = tt[cidx].first - last_end_time;
                m_l_start = last_end_time;
            }
            last_end_time = tt[cidx].second;
        }
        cout << "Day #" << CC++ << ": the longest nap starts at " << int2ts(m_l_start) << " and will last for " << length2td(m_length) << endl;
    }

    return 0;
}
