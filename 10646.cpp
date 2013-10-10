#include <iostream>
#include <cstdio>

using namespace std;

int main(){
    //freopen("10646.in","r",stdin);
    int TC;
    char buf[52][3];
    int x,y,c;
    cin >> TC;
    for(int i=0;i<TC;i++){

        for(int j=0;j<52;j++){
            cin >> buf[j];
        }

        // calculate
        y = 0; c = 24;

        for(int j=0;j<3;j++){
            if(buf[c][0] >= '2' && buf[c][0] <= '9'){
                x = buf[c][0] - '0';
            } else{
                x = 10;
            }
            c -= 1 + (10-x);
            y += x;
        }

        int res = 0;
        if(y > c+1){
            y -= (c+1);
            res = 24 + y;
        }else{
            res = y - 1;
        }

        cout << "Case " << (i+1) << ": " << buf[res] << endl;
    }

    return 0;
}
