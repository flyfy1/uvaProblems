#include <iostream>
#include <map>
#include <algorithm>
#include <string>
#include <vector>
#include <cstdio>

using namespace std;

int main(){
    //freopen("156.in","r",stdin);

    map<string,int> res;
    map<string,string> s_map;
    string buf,tmp;

    while(cin >> buf, buf[0] != '#'){
        tmp = buf;
        transform(tmp.begin(), tmp.end(),tmp.begin(), ::tolower);
        sort(tmp.begin(),tmp.end());
        s_map[tmp] = buf;
        if(res.find(tmp) != res.end()){
            res[tmp]++;
        } else{
            res[tmp] = 1;
        }
    }

    vector<string> output;
    for(map<string,int>::iterator it = res.begin(); it != res.end(); it++){
        //cout << it->first << ", " << it->second << endl;
        if(it->second == 1){
            output.push_back(s_map[it->first]);
        }
    }

    sort(output.begin(),output.end());

    for(vector<string>::iterator it = output.begin(); it != output.end(); it++){
        cout << *it << endl;
    }

    return 0;
}
