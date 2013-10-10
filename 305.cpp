#include <iostream>

using namespace std;

int get_last_round_rank(int lastOut, int current_out, int last_n){
    //cout << "last out: " << lastOut << ", current out: " << current_out << ", last n: " << last_n << endl;
    return (lastOut + 1 + current_out) % last_n;
}

// n: current n
int get_act_out(int c_out, int history[14], int trace_back_num, int n){
    int res = c_out;
    for(int i=0;i<trace_back_num;i++){
        res = get_last_round_rank(history[trace_back_num - 1 - i],res, n + 1 - trace_back_num + i);
    }
    return res;
}

int testJ(int n,int m){
    int history[14];
    int t_n = n * 2;
    // cout << endl << m  << ": " ;
    for(int i = 0;i<n;i++){
        int c_out = (m-1) % t_n;

       // cout << "c_out = " << c_out << endl;
        int act_out = get_act_out(c_out,history,i,2*n);
    //    cout << act_out << " ";
        if(act_out < n) return 0;
        history[i] = c_out;
        t_n -= 1;
    }
    return 1;
}

int main(){
    int n;
    int res[15];
    for(int i=0;i<15;i++){
        res[i] = -1;
    }

    while(cin >> n, n > 0){
        int count = n;
        if(res[n] > 0){
            count = res[n];
        } else{
            while(!testJ(n,++count));
            res[n] = count;
        }
        cout << count << endl;
    }

    return 0;
}
