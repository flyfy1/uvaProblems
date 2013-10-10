#include <iostream>
#include <vector>
#include <string>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#include <set>
#include <stack>
#include <map>

using namespace std;

vector<int> v;
map<int,int> res;

int findSet(int i){
    return (v[i] == i)?i:(v[i] = findSet(v[i]));
}

bool isSameSet(int i, int j){
    return findSet(i) == findSet(j);
}

void unionSet(int i, int j){    // always use the smaller num's parent
    if(res.find(findSet(i)) == res.end()){
        res[findSet(i)] = 1;
    }
    if(res.find(findSet(j)) == res.end() ){
        res[findSet(j)] = 1;
    }

    if(findSet(i) == findSet(j))  return;

    if(i>j){    // keep j
        res[findSet(j)] += res[findSet(i)];
        v[i] = findSet(j);
    } else{     // keep i
        res[findSet(i)] += res[findSet(j)];
        v[j] = findSet(i);
    }
}

map<string,int> m;

int getIndex(string name){
    map<string,int>::iterator t;
    if( (t = m.find(name)) != m.end()){
        return (*t).second;
    } else{
        int index = v.size();
        m.insert(make_pair(name,index));
        v.push_back(index);
        return index;
    }
}

int main(){
    freopen("11503.in","r",stdin);
    int tc,n;
    string bufa,bufb;


    cin >> tc;

    while(tc--){
        m.clear();
        v.clear();
        res.clear();
        cin >> n;

        while(n--){
            cin >> bufa >> bufb;
            int ia = getIndex(bufa);
            int ib = getIndex(bufb);

            unionSet(ia,ib);

            cout << res[findSet(ia)] << endl;
        }
    }
    return 0;
}

