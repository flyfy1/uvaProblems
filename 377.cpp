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

int A[14],B[14],R[14];

void read_str(string buf, int A[]){
    for(int i=0;i<buf.size();i++){
        if(buf[i] == 'V')   A[i+1] = 0;
        else if(buf[i] == 'U')   A[i+1] = 1;
        else if(buf[i] == 'C')   A[i+1] = 2;
        else if(buf[i] == 'D')   A[i+1] = 3;
        else while(1);
    }
    A[0] = buf.size();
    reverse(A+1,A+A[0]+1);
}

void apply_op(char opc,int A[],int B[]){
    if(opc == 'L'){
        for(int i=B[0]+1;i>1;i--){
            B[i] = B[i-1];
        }
        B[1] = 0;
        if(B[B[0]+1])   B[0]++;
    } else if(opc == 'R'){
        for(int i=1;i<B[0];i++){
            B[i] = B[i+1];
        }
        B[B[0]] = 0;
    } else if(opc == 'A'){
        int lasti = 0;
        for(int i=1;i<=A[0] || i<=B[0];i++){
            int t = A[i] + B[i];
            B[i+1] += t/4;
            B[i] = t%4;
            if(B[i+1] > 0)  lasti=i+1;
            else lasti = i;
        }
        B[0] = lasti;
    }
}

int get_arr_val(int A[]){
    int res = 0;
    for(int i=A[0];i>0;i--){
        res *= 4; res += A[i];
    }
    return res;
}

int main(){
    int TC;
    cin >> TC;
    string buf;
    getline(cin,buf);
    cout << "COWCULATIONS OUTPUT" << endl;
    while(TC--){
        getline(cin,buf);
        memset(A,0,sizeof A);
        read_str(buf,A);
        getline(cin,buf);
        memset(B,0,sizeof B);
        read_str(buf,B);
        for(int i=0;i<3;i++){
            getline(cin,buf);
            apply_op(buf[0],A,B);
        }
        getline(cin,buf);
        read_str(buf,R);
        printf("%s\n",get_arr_val(B) == get_arr_val(R)?"YES":"NO");
    }
    cout << "END OF OUTPUT" << endl;

    return 0;
}
