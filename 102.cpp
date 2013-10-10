#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <string>

using namespace std;

int p[] = {0,1,2};
int arr[3][3];
char ans[] = "BGC";
vector<string> v;
string buf;

void copy_ans_to_v(){
    buf.clear();

    for(int i=0;i<3;i++){
        buf.push_back(ans[p[i]]);
    }
    v.push_back(buf);
}

bool get_input(){
    for(int i=0;i<3;i++){
        if(!(cin >> arr[i][0])) return false;
        cin >> arr[i][1] >> arr[i][2];
    }
    return true;
}

void calculate(){
    long long min = 999999999999;
    long long tSum = 0;
    do{
        tSum = 0;

        for(int i=0;i<3;i++){
            for(int j=0;j<3;j++){
                if(j == i)   continue;
                tSum += arr[j][p[i]];
            }
        }

        if(min > tSum){
            v.clear();
            min = tSum;
            copy_ans_to_v();
        } else if(min == tSum){
            copy_ans_to_v();
        }

    }while(next_permutation(p,p+3));

    sort(v.begin(),v.end());

    /*
    for(int i=0;i<v.size();i++){
        cout << v[i] << "  ";
    }
    cout << endl;
    */

    cout << v[0] << " " << min << endl;
}

int main(){
//    freopen("102.in","r",stdin);

    while(get_input()){
        calculate();
    }

    return 0;
}
