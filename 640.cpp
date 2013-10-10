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

int get_digit_sum(int n){
    int sum = 0;
    while(n > 0){
        sum += n%10;
        n /= 10;
    }
    return sum;
}

vector<bool> is_gen(1000005,false);

int main(){
    for(int i=1;i<1000001;i++){
        if(is_gen[i])   continue;
        int gen = get_digit_sum(i) + i;
        while(gen < 1000005 && !is_gen[gen]){
            is_gen[gen] = 1;
            gen = get_digit_sum(gen) + gen;
        }
    }
    for(int i=1;i<1000001;i++){
        if(!is_gen[i])   cout << i << endl;
    }

    return 0;
}
