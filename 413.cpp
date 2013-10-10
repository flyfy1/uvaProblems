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

#define EQ 0
#define UR 1
#define DR 2

using namespace std;

typedef pair<int,int>   ii;
typedef vector<int>     vi;
typedef vector<ii>      vii;
typedef vector<vi>     vvi;
typedef vector<vii>    vvii;
typedef map<int,int>    mii;


int main(){
    int pn,cn;
    while(cin >> pn,pn){
        vi urv,drv;
        int ps = EQ, ur = 0, dr = 0,eqn = 0;
        int valNum = 1;
        while(true){
            cin >> cn;
            int dif = cn - pn;
            if(cn == 0){
                dif = ps;
                ps = -1;
            }
            switch(ps){
                case EQ:
                    if(dif > 0){
                        ur = eqn + 1; eqn = 0; ps = UR;
                    } else if(dif < 0){
                        dr = eqn + 1; eqn = 0; ps = DR;
                    } else{
                        eqn++;
                    }
                    break;
                case UR:
                    if(dif < 0){
                        urv.push_back(ur); ur = 0;
                        dr = 1; ps = DR;
                    } else{
                        ur++;
                    }
                    break;
                case DR:
                    if(dif > 0){
                        drv.push_back(dr); dr = 0;
                        ur = 1; ps = UR;
                    } else{
                        dr++;
                    }
                    break;
                case -1:
                    if(dif == UR){
                        urv.push_back(ur); ur = 0;
                    } else if(dif == DR){
                        drv.push_back(dr); dr = 0;
                    }
                    break;
                default: while(1);
            }

            if(cn == 0) break;
            valNum++;
            pn = cn;
        }
        double sum = 0;
        printf("Nr values = %d: ",valNum);
        for(int i=0;i<urv.size();i++){
            sum += urv[i];
        }
        printf(" %.6lf ",urv.size() == 0?0:sum / urv.size());
        sum = 0;
        for(int i=0;i<drv.size();i++){
            sum += drv[i];
        }
        printf("%.6lf\n",drv.size() == 0?0:sum / drv.size());
    }

    return 0;
}
