/*
Problem ID: 541
Solver: songyy
Start Time: 06/Dec/2011 9am
End Time:   06/Dec/2011 9:20am
Time Spent: 20 min
*/

#include <iostream>
#include <cstdio>

using namespace std;

int buf[100][100];

int main(){
	//freopen("541.in","r",stdin);

    int n,i,j,t;
    int rFirst=-1, cFirst=-1;
    int sum;
    bool corrupt = false;

    while(cin >> n && n != 0){

        // initialize
        corrupt = false;
        rFirst = -1; cFirst = -1;

        for(i=0;i<n;i++){
            for(j=0;j<n;j++){
                cin >> buf[i][j];
            }
        }

        for(i=0;i<n;i++){
            // row count
            sum = 0;
            for(j=0;j<n;j++){
                sum += buf[i][j];
            }
            if(sum % 2){
                if(rFirst == -1){
                    rFirst = i;
                } else{
                    corrupt = true;
                    break;
                }
            }

            // column count
            sum = 0;
            for(j=0;j<n;j++){
                sum += buf[j][i];
            }
            if(sum % 2){
                if(cFirst == -1){
                    cFirst = i;
                } else{
                    corrupt = true;
                    break;
                }
            }
        }

        if(rFirst == -1 && cFirst == -1){
            cout << "OK" << endl;
        } else if(!corrupt && rFirst != -1 && cFirst != -1){
            cout << "Change bit (" << rFirst + 1 << "," << cFirst + 1 << ")" << endl;
        } else{ // corrupted
            cout << "Corrupt" << endl;
        }
    }

    // cout << "Done." << endl;
	return 0;
}
