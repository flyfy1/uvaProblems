#include <iostream>
using namespace std;

int p[] = {0,1,2};
int arr[3][3];
char ans[] = "BCG";

bool get_input(){
    for(int i=0;i<3;i++){
        if(!(cin >> arr[i][0])) return false;
        cin >> arr[i][2] >> arr[i][1];
    }
    return true;
}

int main(){
    while(get_input()){
    }

}
