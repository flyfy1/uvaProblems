/**
 * Problem:
 * Start Time:
 * End Time:
 * Time Spent:
 * Solver: Song Yangyu
 */

#include <iostream>
#include <cstring>

using namespace std;

int b,w;
char map[1000][1000];
int count[1000][1000];

/**
 * Mark the current point
 * Return 1 when the ending point reached, 0 when not
 */
int move(){

}

int main(){


    while(cin >> b >> w, b != 0){
        for(int i=0;i<b;i++){
            cin >> map[i];
        }

        memset(count,sizeof(int) * 1000 * 1000, 0);
        int x = b-1,y=0;
        while(move(b-1,x,y));
    }
}

