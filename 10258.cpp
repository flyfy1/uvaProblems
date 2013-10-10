#include <iostream>
#include <set>
#include <string>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <cstring>

#define PN  15

using namespace std;

int pn[100][PN], tn[100][PN];

struct Res{
    int p;  // # problems solved
    int t;  // # of time spent
    int n;  // team number

    Res(int a,int b,int c){
        p = a, t = b, n = c;
    }
};

bool cmpFunc(struct Res a, struct Res b){
    if(a.p != b.p)  return a.p - b.p > 0;
    else if(a.t != b.t) return a.t - b.t <= 0;
    else return a.n - b.n <= 0;
}

int main(){
    int TC;
    int c,p,t;
    char r;
    bool first = true;
    string buf;
    cin >> TC;
    getline(cin,buf);
    getline(cin,buf);
    while(TC--){
        if(first)   first = false;
        else cout << endl;
        set<int> s;
        vector<struct Res> res;
        memset(pn,0,sizeof(pn));
        for(int i=0;i<100;i++)  for(int j=0;j<PN;j++)   tn[i][j] = -1;

        while(getline(cin,buf) && buf!=""){
            //cout << "buf = " << buf << endl;
            sscanf(buf.c_str(),"%d%d%d %c",&c,&p,&t,&r);
            //cout << "r = " << r << endl;
            s.insert(c);
            if(tn[c-1][p-1] != -1)  continue;   // correct already. ignore
            else if(r == 'C'){
             //   cout << "readed. " << endl;
                tn[c-1][p-1] = t;
            }
            else if(r == 'I'){
                pn[c-1][p-1]++;
            }
            
            /*
            cout << "current sequence: " << endl;
            for(int i=58;i<=61;i++){
                for(int j=0;j <= PN; j++){
                    cout << tn[i][j] << " ";
                }
                cout << endl;
            }
            */

        }

        // then iterate through to get the output
        for(set<int>::iterator it = s.begin(); it != s.end();it++){
            int n = (*it) - 1; 
            int time = 0, pro = 0;
            for(int i=0;i<PN;i++){
                if(tn[n][i] != -1){
                    pro++;
                    time += tn[n][i] + pn[n][i] * 20;
                }
            }
            
            // cout << "pro: " << pro << ", n = " << n << endl;

            struct Res *st_res = new Res(pro,time,n+1);
            
            //printf("declare: %d %d %d\n",st_res->n,st_res->p,st_res->t);
            res.push_back(*st_res);
        }
        sort(res.begin(),res.end(),cmpFunc);

        for(int i=0;i<res.size();i++){
            printf("%d %d %d\n",res[i].n,res[i].p,res[i].t);
        }
    }
}
