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

using namespace std;

typedef pair<int,int>   ii;
typedef vector<int>     vi;
typedef vector<ii>      vii;

int dist[105][105];
int allo[105][5];

int main(){
    string buf;
    map<char,int> ml,mu;
    ml['r'] = 0;ml['o'] = 1;ml['y'] = 2;ml['g'] = 3;ml['b'] = 4;
    mu['P'] = 0;mu['G'] = 1;mu['S'] = 2;mu['A'] = 3;mu['N'] = 4;
    int CC;
    while(true){
        CC = 0;
        memset(dist,0,sizeof dist); memset(allo,0,sizeof allo);
        while(getline(cin,buf),buf[0] != 'e' && buf[0] != '#'){
            char a,b;
            istringstream in(buf);
            while(true){
                in >> a >> b >> b;
                allo[CC][ml[a]] = mu[b];

                if(!(in >> a)){
                    break;
                }
            }
            CC++;
        }
        if(buf[0] == '#')   break;

        // then calculate the dist
        for(int i=0;i<CC;i++){
            for(int j = i+1;j<CC;j++){
                int dif = 0;
                for(int k = 0;k<5;k++)  if(allo[i][k] != allo[j][k])    dif++;
                dist[i][j] = dist[j][i] = dif;
            }
        }
        int city = 0,min = 2000000000;
        for(int i=0;i<CC;i++){
            int sum = 0;
            for(int j=0;j < CC;j++){
                sum += dist[i][j];
            }
            if(sum < min){
                min = sum; city = i+1;
            }
        }

        cout << city << endl;
    }

    return 0;
}
