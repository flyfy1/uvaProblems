#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main(){
    int TC, R,C,M,N;
    string buf;
    cin >> TC;
    for(int TT = 0;TT<TC;TT++){
        vector<int> v(26);
        
        cin >> R >> C >> M >> N;
        for(int i=0;i<R;i++){
            cin >> buf;
            for(int j=0;j<buf.size();j++){
                v[buf[j] - 'A']++;
            }
        }
        
        int res = 0;
        // find out the max
        int max = -1, val = -1;
        for(int i=0;i<26;i++){
            if(max < v[i]){
                max = v[i]; val = i;
            }
        }

        for(int i = 0;i<26;i++){
            if(max == v[i]) res += v[i] * M;
            else res += v[i] * N;
        }
        
        cout << "Case " << TT+1 << ": " << res << endl;
    }
    return 0;
}
