/**
 * Problem:
 * Start Time:
 * End Time:
 * Time Spent:
 * Solver: Song Yangyu
 */

#include <iostream>

using namespace std;

int main(){
    int TC;
    cin >> TC;

    int a,b;
    int x,y;

    while(TC--){
        cin >> a >> b;
        int dbx = a+b;
        if(dbx&1){
            cout << "impossible" << endl;
            continue;
        }

        x = dbx/2;
        int dby = a-b;
        if(dby<0){
            cout << "impossible" << endl;
            continue;
        }

        cout << x << " " << dby/2 << endl;
    }

}
