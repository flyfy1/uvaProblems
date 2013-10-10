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

#define M_SIZE  110

bool  adjM[M_SIZE][M_SIZE];
int   inDeg[M_SIZE];
bool  visited[M_SIZE];

using namespace std;

typedef pair<int,int>   ii;

int main(){
    int N,M;
    string bufa,bufb;
    int na,nb;
    int CC = 1;
    
    while(cin >> N){
        map<string,int> m;
        map<int,string> back;
        memset(adjM,0,sizeof adjM);
        memset(inDeg,0,sizeof inDeg);
        memset(visited,0,sizeof visited);
        int count  = 0;
        for(int i=0;i<N;i++){
            cin >> bufa;
            m[bufa] = count;
            back[count++] = bufa;
        }
        cin >> M;
        for(int i=0;i<M;i++){
            cin >> bufa >> bufb; 
            na = m[bufa]; nb = m[bufb];
            if(!adjM[na][nb]) inDeg[nb]++;
            adjM[na][nb] = true;
        }
        
        // perform a simple check here
        // for(int i=0;i<N;i++)    printf("%d ",inDeg[i]);
        // putchar('\n');
        
        // then perform bfs
        int eleToVisit = N;
        printf("Case #%d: Dilbert should drink beverages in this order:",CC++);

        while(eleToVisit){
            for(int i=0;i<N;i++){
                if(!visited[i] && inDeg[i] == 0){
                    for(int j=0;j<N;j++){
                        if(adjM[i][j])  inDeg[j]--;
                    }
                    cout << " " << back[i];
                    eleToVisit--; visited[i] = true;
                    break;
                }
            }
        }
        cout << "." << endl << endl;
    }

    return 0;
}
