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

using namespace std;

typedef pair<int,int>   ii;
typedef vector<int>     vi;
typedef vector<ii>      vii;
typedef vector<vi>     vvi;
typedef vector<vii>    vvii;

bool mm[700][700];
int cn;
int p[700];

void addRote(string as, string bs, map<string,int> &mp, map<int,string> &mb){
    int a,b;
    if(mp.count(as)) a = mp[as];
    else{
        a= cn;
        mb[cn] = as;
        mp[as] = cn++; 
    }

    if(mp.count(bs)) b = mp[bs];
    else{
        b= cn;
        mb[cn] = bs;
        mp[bs] = cn++; 
    }

    mm[a][b] = mm[b][a] = 1;
}

int main(){
    int rn;
    string as, bs;
    int a,b;
    bool first = true;
    while(cin >> rn){
        if(first) first =false;
        else putchar('\n');
        cn = 0;
        memset(mm,0,sizeof mm);
        map<string,int> mp;
        map<int,string> mb;
        for(int i=0;i<rn;i++){
            cin >> as >> bs;
            addRote(as,bs,mp,mb);
        }
        cin >> as >> bs;
        if(!mp.count(as) || !mp.count(bs)){
            printf("No route\n");
            continue;
        }
        int s = mp[as], e = mp[bs];
        for(int i=0;i<700;i++)  p[i] = -1;
        queue<int> q;
        q.push(s);
        while(!q.empty()){
            int u = q.front(); q.pop();
            if(u == e)  break;
            for(int i=0;i<cn;i++){
                if(mm[u][i] && p[i] == -1 && i != s){
                    p[i] = u; q.push(i);
                }
            }
        }

        stack<int> S;
        while(p[e] != -1){
            S.push(e); e = p[e];
        }

        if(e != s){
            printf("No route\n");
            continue;
        }

        int pr;
        while(!S.empty()){
            pr = e; e = S.top(); 
            cout << mb[pr] << " " << mb[e] << endl;
            S.pop();
        }
    }
    return 0;
}
