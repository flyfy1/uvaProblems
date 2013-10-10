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

#define EPS 1e-7

typedef struct Node{
    double v;
    int no,de;
    Node(int _no,int _de){
        no = _no; de = _de;
        v = _no; v /= _de;
    }
    const bool operator==(const Node b) const{
        return abs(b.v - v) < EPS;
    }
    const bool operator<(const Node b) const{
        return v + EPS < b.v;
    }
};

int main(){
    int n,k;
    while(cin >> n >> k){
        set<Node> v;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                v.insert(Node(i,j));
            }
        }
        set<Node>::iterator it = v.begin();
        while(k > 1){
            it++; k--;
        }
        printf("%d/%d\n",it->no,it->de);
    }

    return 0;
}
