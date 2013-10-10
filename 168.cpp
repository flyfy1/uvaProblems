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
typedef vector<vi>      vvi;


int main(){
    string buf;
    while(getline(cin,buf),buf[0] != '#'){
        int pos = 0;
        char c;
        vvi el(26);
        while(c = buf[pos++], isalpha(c)){
            int s = c - 'A';
            pos++;
            while(c = buf[pos++],isalpha(c)) el[s].push_back(c - 'A');
        }
        c = buf[pos++];pos++;
        int M = c - 'A';// pos of monster
        c = buf[pos++];
        int H = c - 'A';    // pos of hunter
        int k;
        sscanf(buf.c_str() + pos,"%d",&k);
        vector<bool> candle(26,false);
        
        // then simulate -- assume M is in H's next node
        int pC = 0;
        while(true){
            int nM = M;
            for(int i=0;i<el[M].size();i++){
                int cc = el[M][i];
                if(cc != H && !candle[cc]){
                    nM = cc; break;
                }
            }
            if(nM == M) break;  // trapped
            pC++;
            H = M;
            if(pC % k == 0){
                candle[H] = true;
                printf("%c ",H + 'A');
            }
            M = nM;
        }
        printf("/%c\n",M+'A');
    }
    return 0;
}
