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

using namespace std;

typedef pair<int,int>   ii;

using namespace std;

// union find alg
// use negative number to note # of elements inside a set
vector<int> v;
int numDisjointSets;

void init(int n){
    v.assign(n,-1);
    numDisjointSets = n;
}

int findSet(int i){
    return (v[i] < 0)?i:(v[i] = findSet(v[i]));
}

bool isSameSet(int i, int j){
    return findSet(i) == findSet(j);
}

void unionSet(int i, int j){
    if(i < j){
        if(!isSameSet(i,j)){
             v[findSet(i)] += v[findSet(j)];
             numDisjointSets--;
        }
        v[j] = findSet(i);
    } else{
        if(!isSameSet(i,j)){
            v[findSet(j)] += v[findSet(i)];
            numDisjointSets--;
        }
        v[i] = findSet(j);
    }
}

int elesNumInSet(int i){
    return -v[findSet(i)];
}

int main(){
    int TC,m,n;
    string buf;

    scanf("%d",&TC);
    while(TC--){
        int ca = 0, ua = 0;
        int size;
        scanf("%d",&size);
        getline(cin,buf);
        init(size);
        while(getline(cin,buf),buf[0] == 'c' || buf[0] == 'q'){
            // cout << buf << endl;
            sscanf(buf.c_str(),"%*c %d%d",&m,&n);
            m--;n--;
            
            if(buf[0] == 'c'){
                unionSet(m,n);
            } else{
                if(isSameSet(m,n))   ca++;
                else        ua++;
            }
        }
        printf("%d,%d\n",ca,ua);
    }

    return 0;
}
