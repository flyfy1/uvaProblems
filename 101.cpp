#include <iostream>
#include <vector>
#include <string>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#include <set>

using namespace std;

vector< vector<int> > v;
vector<int> pos;

void return_all_on_top_of(int a,int posA){
    int c_pos = pos[a];
    for(int i = posA + 1; i < v[c_pos].size(); i++){
        // return it to it's original position
        pos[v[c_pos][i]] = v[c_pos][i];
        v[pos[v[c_pos][i]]].push_back(v[c_pos][i]);
    }
    v[c_pos].erase(v[c_pos].begin() + posA + 1,v[c_pos].end());
    return;
}

void output(int n){
    for(int i=0;i<n;i++){
        cout << i << ":";
        for(int j=0;j<v[i].size();j++){
            cout << " " << v[i][j];
        }
        cout << endl;
    }
}

void output_pos_list(int n){
    cout << "pos list: ";
    for(int i=0;i<n;i++){
        cout << pos[i] << " ";
    }
    cout << endl;
}

int main(){
 //   freopen("101.in","r",stdin);
    int n;

    cin >> n;
    v.clear();
    pos.resize(n);
    v.resize(n,vector<int>(1));

    // ini
    for(int i=0;i<n;i++){
        pos[i] = i;
        v[i][0] = i;
    }


    string buf;
    char cmdA[10],cmdB[10];
    int a,b;    // integer a,b

    getline(::cin,buf);
    while(getline(::cin,buf),buf != "quit"){
        sscanf(buf.c_str(),"%s%d%s%d",cmdA,&a,cmdB,&b);
 //       printf("%s %d %s %d\n",cmdA,a,cmdB,b);

        // invalid commmands -- continue
        if(pos[a] == pos[b])    continue;

        int posA = find(v[pos[a]].begin(),v[pos[a]].end(),a) - v[pos[a]].begin();
        int posB = find(v[pos[b]].begin(),v[pos[b]].end(),b) - v[pos[b]].begin();

        if(posA == v[pos[a]].size() || posB == v[pos[b]].size()){
            cout << "pos errror" << endl;
        }

        if(strcmp(cmdA,"move") == 0){
            // return all on top of a
            return_all_on_top_of(a,posA);
//            cout << "return cuz of move " << endl;
        } else{
            // pile, do nothing
        }

        if(strcmp(cmdB,"onto") == 0){
            // return all on top of b
            return_all_on_top_of(b,posB);
//            cout << "return cuz of onto " << endl;
        } else{
            // over, do nothing
        }

        // then pile a over b
        int c_posA = pos[a];
        for(int i = posA;i < v[c_posA].size();i++){
            pos[v[c_posA][i] ] = pos[b];
            v[pos[b]].push_back(v[c_posA][i]);
        }

        v[c_posA].erase(v[c_posA].begin() + posA,v[c_posA].end());
    }
    output(n);
}

