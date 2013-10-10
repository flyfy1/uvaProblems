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
#define LNUM    26

using namespace std;

typedef pair<int,int>   ii;
typedef vector<int>     vi;
typedef vector<ii>      vii;

bool graph[LNUM];
bool mm[LNUM][LNUM];
vector<vi> el;
vector<int> S;
int MIN = 2000000000;
bool visited[LNUM];
int eleCount = -1;
int pos[LNUM];

int getGBandwidth(){
    int gmax = -1;
    for(int i=0;i<S.size();i++) pos[S[i]] = i;
    for(int i=0;i<S.size();i++){
        int emax = 0;
        for(int j=0;j<el[S[i]].size();j++)
            emax = max(emax,abs(i - pos[el[S[i]][j]]));
        gmax = max(gmax,emax);
    }
    return gmax;
}

vector<int> RES;

void cal(int s){
    visited[s] = 1;
    S.push_back(s);
    if(S.size() == eleCount){
        // output this s
        // printf("s: ");
        // for(int i=0;i<S.size();i++) printf("%c ",S[i] + 'A');
        int gb = getGBandwidth();
        if(MIN > gb){
            MIN = gb;
            RES = vi(S);
        }
        // cout << gb << endl;
    } else{
        for(int i = 0;i<LNUM;i++){
            if(!visited[i] && graph[i]){
                cal(i);
            }
        }
    }
    S.pop_back();
    visited[s] = 0;
}

int main(){
    string buf;
    while(getline(cin,buf),buf[0] != '#'){
        // cout << "buf: " << buf << endl;
        memset(mm,0,sizeof mm);
        memset(graph,0,sizeof graph);
        istringstream in(buf);
        char c;
        while(in >> c){
            int u = c - 'A';
            graph[u] = 1;
            in >> c;
            while(in >> c && c != ';'){
                mm[u][c - 'A'] = true;
                mm[c - 'A'][u] = true;
                graph[c - 'A'] = true;
            }
        }
        el = vector<vi>(LNUM);
        for(int i=0;i<LNUM;i++) for(int j=0;j<LNUM;j++) if(mm[i][j]) el[i].push_back(j);
        eleCount = 0;
        for(int i=0;i<LNUM;i++) if(graph[i]) eleCount++;
        //cout << "ele num: " << eleCount << endl;
        memset(visited,0,sizeof visited);
        MIN = 2000000000;
        // calculate the best allignment
        //for(int i=0;i<LNUM;i++) if(graph[i]) cal(i);
        cal(0);
        // then output
        for(int i=0;i<RES.size();i++){
            putchar(RES[i] + 'A');putchar(' ');
        }
        printf("-> %d\n",MIN);
    }

    return 0;
}
