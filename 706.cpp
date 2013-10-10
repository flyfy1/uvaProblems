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

char nums[10][5][4] = {
    {" - ",
     "| |",
     "   ",
     "| |",
     " - "},
    {"   ",
     "  |",
     "   ",
     "  |",
     "   "},
    {" - ",
     "  |",
     " - ",
     "|  ",
     " - "},
    {" - ",
     "  |",
     " - ",
     "  |",
     " - "},
    {"   ",
     "| |",
     " - ",
     "  |",
     "   "},
    {" - ",
     "|  ",
     " - ",
     "  |",
     " - "},
    {" - ",
     "|  ",
     " - ",
     "| |",
     " - "},
    {" - ",
     "  |",
     "   ",
     "  |",
     "   "},
    {" - ",
     "| |",
     " - ",
     "| |",
     " - "},
    {" - ",
     "| |",
     " - ",
     "  |",
     " - "},
};

int s,n;

void output_num_line(int c,int ln){
    putchar(nums[c][ln][0]);
    for(int i=0;i<s;i++)    putchar(nums[c][ln][1]);
    putchar(nums[c][ln][2]);
}

int main(){
    while(cin >> s >> n, s || n){
        vector<int> v;
        if(n == 0)  v.push_back(0);
        while(n){
            v.push_back(n%10); n /= 10;
        }
        reverse(v.begin(),v.end());
        
        // output the num
        for(int ln = 0; ln < 5; ln++){
            if(ln == 1 || ln == 3){
                for(int tln = 0; tln < s; tln++){
                    for(int idx = 0;idx < v.size();idx++){
                        if(idx != 0)    putchar(' ');
                        output_num_line(v[idx],ln);
                    }
                    putchar('\n');
                } 
            }else{
                for(int idx = 0;idx < v.size();idx++){
                    if(idx != 0)    putchar(' ');
                    output_num_line(v[idx],ln);
                }
                putchar('\n');
            }
            // end of line, output the new line
        }
        putchar('\n');
    }

    return 0;
}
