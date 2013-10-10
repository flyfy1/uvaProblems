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
    int X,I,J;
    char buf[10];

    while(cin >> X >> I >> J, X || I || J){
        sprintf(buf,"%d",X);
        string outStr(buf),ss;
        
        I--;
        while(I--){
            ss = outStr;
            outStr.clear();
            char pc = ss[0]; int cnt = 1;
            for(int i=1;i<ss.size() && i < 1020;i++){
                if(pc == ss[i]){
                    cnt++;
                } else{
                    sprintf(buf,"%d%c",cnt,pc);
                    outStr.append(buf);
                    pc = ss[i]; cnt = 1;
                }
                
            }
            if(cnt > 0){
                sprintf(buf,"%d%c",cnt,pc);
                outStr.append(buf);
            }
        }
        cout << outStr[J-1] << endl;
    }

    return 0;
}
