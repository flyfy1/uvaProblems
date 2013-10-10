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

char chars[27][5][7];
char char_buf[3][5][65] = {
    {
    ".***.. ****.. .****. ****.. *****. *****. .****. *...*. *****.",
    "*...*. *...*. *...*. *...*. *..... *..... *..... *...*. ..*...",
    "*****. ****.. *..... *...*. ***... ***... *..**. *****. ..*...",
    "*...*. *...*. *..... *...*. *..... *..... *...*. *...*. ..*...",
    "*...*. ****.. .****. ****.. *****. *..... .***.. *...*. *****."
    },
    {
    "..***. *...*. *..... *...*. *...*. .***.. ****.. .***.. ****..",
    "...*.. *..*.. *..... **.**. **..*. *...*. *...*. *...*. *...*.",
    "...*.. ***... *..... *.*.*. *.*.*. *...*. ****.. *...*. ****..",
    "*..*.. *..*.. *..... *...*. *..**. *...*. *..... *..**. *..*..",
    ".**... *...*. *****. *...*. *...*. .***.. *..... .****. *...*."
    },
    {
    ".****. *****. *...*. *...*. *...*. *...*. *...*. *****. ......",
    "*..... *.*.*. *...*. *...*. *...*. .*.*.. .*.*.. ...*.. ......",
    ".***.. ..*... *...*. .*.*.. *.*.*. ..*... ..*... ..*... ......",
    "....*. ..*... *...*. .*.*.. **.**. .*.*.. ..*... .*.... ......",
    "****.. .***.. .***.. ..*... *...*. *...*. ..*... *****. ......"
    }
};

bool first = true;

char pbuf[60][61];

void init_page(){
    for(int i=0;i<60;i++){
        for(int j=0;j<60;j++)   pbuf[i][j] = '.';
    }
}

void output_page(){
    if(first) first = false;
    else    putchar('\n');

    for(int i=0;i<60;i++){
        for(int j=0;j<60;j++)   putchar(pbuf[i][j]);
        putchar('\n');
    }

    putchar('\n');
    for(int i=0;i<60;i++)   putchar('-');
    putchar('\n');
}

void put_to_page_f1(int r,int c,char str[]){
    int l = strlen(str);   // c is the starting loc
    if(c < 0){ str -= c; c = 0; }
    for(int i=0;i<l && i+c < 60;i++){
        if(str[i] == ' ')   continue;
        pbuf[r][i+c] = str[i];
    }
    return;
}

void put_to_page_f5(int r,int c, char str[]){
    int l = strlen(str);
    for(int i=0;i<l;i++)    if(str[i] == ' ')   str[i] = 'Z'+1;

    for(int i=0;i < l && i*6 + c < 60;i++){
        for(int j=0;j<5 && r + j < 60;j++){ // line num
            for(int k=0;k<6 && c+i*6+k < 60;k++){
                if(c+i*6+k < 0) continue;
                if(chars[str[i]-'A'][j][k] == '.')  continue;
                pbuf[r+j][c+i*6+k] = chars[str[i]-'A'][j][k];
            }
        }
    }
}

void put_str(char ft_size,char p,int r,char str[]){
    int l = strlen(str);
    if(ft_size == '1'){
        switch(p){
            case 'L':
                put_to_page_f1(r-1,0,str);
                break;
            case 'R':
                put_to_page_f1(r-1,60-l,str);
                break;
            case 'C':
                put_to_page_f1(r-1,30-l/2,str);
                break;
            default:
                printf("Err str: %c\n",p);
                while(1);
                break;
        }
    } else if(ft_size == '5'){
        switch(p){
            case 'L':
                put_to_page_f5(r-1,0,str);
                break;
            case 'R':
                put_to_page_f5(r-1,60-6*l,str);
                break;
            case 'C':
                put_to_page_f5(r-1,30-l*3,str);
                break;
            default:
                printf("Err str: %c\n",p);
                while(1);
                break;
        }
    } else{
        while(1);   // wrong param passed in
    }
}

void put_str_abs(char ft_size,int r,int c,char str[]){
    if(ft_size == '1'){
        put_to_page_f1(r-1,c-1,str);
    } else if(ft_size == '5'){
        put_to_page_f5(r-1,(c-1),str);
    } else{
        while(1);   // wrong param passed in
    }
}

void parse_cmd(string cmds){
    int p1,p2;
    char bufs[170];
    char font[3];
    switch(cmds[1]){
        case 'C': case 'L': case 'R':   // foun
            scanf("%s%d %*c%[^|]%*c ",font,&p1,bufs);
            put_str(font[1],cmds[1],p1,bufs);
            break;
        case 'P': 
            scanf("%s%d%d %*c%[^|]%*c ",font,&p1,&p2,bufs);
            put_str_abs(font[1],p1,p2,bufs);
            break;
        case 'E':
            // output the page directly
            output_page();
            init_page();
            break;
        default:    
            printf("Err str, cmd = %s\n",cmds.c_str());
            while(1);
    }
}


int main(){
    // do a translation to the proper C5 output string first
    char buf[70];
    for(int i=0;i<3;i++){
        for(int j=0;j<5;j++){
            string s = string(char_buf[i][j]);
            istringstream in(s);
            for(int k=0;k<9;k++){
                in >> chars[9*i + k][j];
            }
        }
    }

    /* 
    for(int k=0;k<27;k++){
        for(int i=0;i<5;i++){
            for(int j=0;j<6;j++)    putchar(chars[k][i][j]);
            putchar('\n');
        }
        putchar('\n');
    }
    return 0;
    */

    // parse the command
    init_page();
    while(scanf("%s",buf) == 1){
        parse_cmd(buf);
    }

    return 0;
}
