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
typedef vector<int>     vi;
typedef vector<ii>      vii;

vi ans[4];


int main(){
    int arr[] = {10,100,1000,10000};
//    cout << "begin" << endl;
    for(int k=0;k<4;k++)
        for(int i=0;i<arr[k];i++)
            for(int j=0;j<arr[k];j++)
                if(i * arr[k] + j == (i+j)*(i+j))  ans[k].push_back(i*arr[k] + j);
    for(int i=0;i<4;i++)    sort(ans[i].begin(),ans[i].end());
  //  cout << "up to here " << endl;
    int t;
    char fmt[] = "%0nd\n";
    while(scanf("%d",&t) != EOF){
        fmt[2] = t + '0';
        t /= 2;
        for(int i=0;i<ans[t-1].size();i++) printf(fmt,ans[t-1][i]);
    }
    return 0;
}
