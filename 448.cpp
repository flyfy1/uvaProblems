#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include <cstdio>
#include <cstring>
#include <string.h>
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

int hex2dec(char c){
    if(c >= '0' && c <= '9')    return c - '0';
    if(c >= 'A' && c <= 'F')    return c - 'A' + 10;
    
    // error case
    printf("Err, c = %c\n",c);
    while(1);   // This would cause an TLE, therefore I know it's cuz of error here.
    return 0;
}

char ops_map[4][4] = {"R","$","PC+",""};

void get_oprand_str(char s[],char o[]){
    strcpy(o,"");
    int op = hex2dec(s[0]);
    strcat(o,ops_map[(op & 0xD) >> 2]);
    op &= 3;
    for(int i=1;i<4;i++){
        op <<= 4;
        op += hex2dec(s[i]);
    }
    char buf[7] = "";
    sprintf(buf,"%d",op);
    strcat(o,buf);
    return;
}

void read_oprand_str(char t[]){
    int idx = 0;
    char buf[10];
    while(idx < 4){
        buf[idx] = getchar();
        if(buf[idx] != '\n')  idx++;
    }
    buf[idx] = 0;
    get_oprand_str(buf,t);
    return;
}

char map_cmd[16][6] = {
    "ADD", "SUB", "MUL", "DIV", "MOV", "BREQ", "BRLE", "BRLS",
    "BRGE","BRGR","BRNE","BR",  "AND", "OR",   "XOR",  "NOT",
};

void parse_cmd(char c){
    int cmd = hex2dec(c);
    char buf[10];
    printf("%s ",map_cmd[cmd]);
    if(cmd <= 4){   // 2 oprand
        read_oprand_str(buf);
        printf("%s,",buf);
        read_oprand_str(buf);
        printf("%s\n",buf);
    } else if( cmd >= 0xC && cmd <= 0xE){ // 3 oprand
        read_oprand_str(buf);
        printf("%s,",buf);
        read_oprand_str(buf);
        printf("%s,",buf);
        read_oprand_str(buf);
        printf("%s\n",buf);
    } else{ // 1 oprand
        read_oprand_str(buf);
        printf("%s\n",buf);
    }
    return;
}

int main(){
    char c;
    while(scanf("%c",&c) == 1){
        if(c == '\n')   continue;
        parse_cmd(c);
    }

    return 0;
}
