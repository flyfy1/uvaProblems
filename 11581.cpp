#include <iostream>
#include <string>
using namespace std;

int g[3][3];
int ta[3][3];

int arr_x[] = {-1,0,0,1}, arr_y[] = {0,-1,1,0};

void update(int a, int b){
    int sum = 0;
    int x,y;
    ta[a][b] = 0;
    for(int i=0;i<4;i++){
        x = a + arr_x[i];
        y = b + arr_y[i];
        if(x < 0 || y < 0 || x >= 3 || y >= 3)  continue;
        ta[a][b] += g[x][y];
    }
    ta[a][b] &= 1;
}

int main(){
    int TC;
    string buf;

    cin >> TC;

    while(TC--){
        bool alZ = true;

        for(int i=0;i<3;i++){
            cin >> buf;
            for(int j=0;j<3;j++){
                g[i][j] = buf[j] - '0';
                if(g[i][j]) alZ = false;
            }
        }

        if(alZ){
            cout << -1 << endl;
            continue;
        }

        // then calculate
        int res = 0;
        while(1){
            alZ = true;
            for(int i=0;i<3;i++){
                for(int j=0;j<3;j++){
                    update(i,j);      
                    if(ta[i][j])    alZ = false;
                    //cout << "t i j = " << ta[i][j] << ".";
                }
            }
            
            // then copy over
            for(int i=0;i<3;i++)    for(int j=0;j<3;j++)    g[i][j] = ta[i][j];

            if(alZ) break;
            else    res++;
        }

        cout << res << endl;
    }
}

