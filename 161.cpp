#include <iostream>
#include <cstdio>

using namespace std;

int get_next(int current, int arr[], int n){
    int minV = 9999999,t;
    for(int i=0;i<n;i++){
        t = arr[i] - current%arr[i];
        if(minV > t){
            minV = t;
        }
    }
    return current + minV;
}

int main(){
    //freopen("161.in","r",stdin);
    int arr[100];
    int n = 0;

    while(true){
        n = 0;
        int minV = 9999999;
        while(cin >> arr[n],arr[n] != 0){
            minV = min(arr[n],minV);
            n++;
        }


        if(n == 0){
            break;
        }

        int time = minV * 2, res = -1;
        while(time <= 5 * 60 * 60){
            bool not_this = false;
            for(int i=0;i<n;i++){
                int t = time % (2*arr[i]);
                if(t >= arr[i] - 5){
                    not_this = true;
                    break;
                }
            }

            if(!not_this){
                res = time;
                break;
            }

            time = get_next(time,arr,n);
        }

        if(res > 0) printf("%02d:%02d:%02d\n",res / 3600,(res %3600)/ 60,res % 60);
        else cout << "Signals fail to synchronise in 5 hours" << endl;
    }
}
