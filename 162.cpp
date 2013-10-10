// somehow don't know why this is different from the example program given
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

deque<int>  p[2];
char buf[5];

int trans(char c){
    if(c > '1' && c <= '9') return c - '0';
    else if(c == 'T')   return 10;
    else if(c == 'A')   return 14;
    else if(c == 'J')   return 11;
    else if(c == 'Q')   return 12;
    else if(c == 'K')   return 13;
    else return -1;
}

int _CNT_formatted_output = 0;
void formatted_output(const char* str){
    if(_CNT_formatted_output % 10 == 0)  printf("\t");
    cout << str << '\t';
    if(_CNT_formatted_output % 10 == 9)  printf("\n");
    _CNT_formatted_output++;
}
void formatted_output_newLine(const char* str){
    if(_CNT_formatted_output % 10 != 0) putchar('\n');
    cout << str << endl; _CNT_formatted_output = 0;
}

void print_dack(deque<int> *p,deque<int> s){
    putchar('\n');
    for(int n=0;n<2;n++){
        printf("%d:",n);
        for(deque<int>::iterator it = p[n].begin(); it != p[n].end(); ++it){
            printf("%4d",*it);
        }
        putchar('\n');
    }
    printf("s:");
    for(deque<int>::iterator it = s.begin(); it != s.end(); ++it){
        printf("%4d",*it);
    }
    putchar('\n');
}

int main(){
    while(true){
        p[0].clear();
        p[1].clear();
        cin >> buf;
        if(buf[0] == '#')   break;

        p[0].push_back(trans(buf[1]));
        for(int i=1;i<52;i++){
            cin >> buf;
            p[i&1].push_back(trans(buf[1]));    // 1 is the dealer
        }
        
        // init the play
        bool pnum = 0;  // # of current player
        int cover = 0;  // # of cards to be placed by the next player
        deque<int> s;   // # the card stack currently in play

        while(!p[pnum].empty()){
            int thisCard = p[pnum].back();
            p[pnum].pop_back(); s.push_back(thisCard);

            // my dear DEBUGGING INFO
            // print_dack(p,s);
            // char bf[100];  
            // sprintf(bf,"(%d,%d)",pnum,thisCard);
            // sprintf(bf,"(%d,%d)",pnum,thisCard);
            // formatted_output(bf);

            if(thisCard > 10){  // faced card
                cover = thisCard - 10;  // set cover to be removed
                pnum = !pnum;           // take turns to play
            } else if(cover == 1){
                cover = 0; pnum = !pnum;    // switch turn
                p[pnum].insert(p[pnum].begin(),s.rbegin(),s.rend()); s.clear();

                // DEBUGGING INFO
                // sprintf(bf,"take all, by %d",pnum);
                // formatted_output_newLine(bf);
            } else if(cover > 1){
                cover--;
            } else{
                pnum = !pnum;
            }
        }
        // the ended pnum is the loser because it has no card to play
        pnum = !pnum;  
        printf("%d%3d\n",!pnum+1,(int)(p[pnum].size()));
    }
    return 0;
}
