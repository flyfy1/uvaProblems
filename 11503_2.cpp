#include <iostream>
#include <cstdio>
#include <vector>
#include <map>

using namespace std;

// union find alg
// use negative number to note # of elements inside a set
vector<int> v;
int numDisjointSets;

void init(int n){
    v.clear();
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
    i = findSet(i); j = findSet(j);
    if(i == j){
        return;
    } else if(i < j){
        v[i] += v[j];
        v[j] = i;
    } else{
        v[j] += v[i];
        v[i] = j;
    }
    numDisjointSets--;
}

int unionAdd(){
    v.push_back(-1);
    numDisjointSets++;
    return v.size() - 1;
}

int elesNumInSet(int i){
    return -v[findSet(i)];
}

int main(){
    int tc,n,t;
    string bufA,bufB;
    map<string,int> m;
    int a,b;

    freopen("11503.in","r",stdin);

    cin >> tc;


    while(tc--){
        cin >> n;
        init(0);
        m.clear();

        while(n--){
            cin >> bufA >> bufB;

//            cout << bufA << ", " << bufB;

            if(m.find(bufA) != m.end()){
                a = m[bufA];
            } else{
                a = unionAdd();
                m.insert(make_pair(bufA,a));
            }

            if(m.find(bufB) != m.end()){
                b = m[bufB];
            } else{
                b = unionAdd();
                m.insert(make_pair(bufB,b));
            }

//            cout << "; a = " << a << ", b = " << b << endl;

            unionSet(a,b);

            cout << elesNumInSet(a) << endl;

        }

    }

    return 0;
}

