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

    return 0;
}
