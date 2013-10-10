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
#define MAX 1l << 62

using namespace std;

typedef pair<int,int>   ii;
typedef pair<long long,long long>   llll;
typedef vector<int>     vi;
typedef vector<ii>      vii;
typedef vector<llll>      vllll;
typedef vector<long long>      vll;
typedef vector<vi>     vvi;
typedef vector<vii>    vvii;

int N,M;
long long D,K;
llll mm[105][105];
int p[105];
long long minT = 0;

void augment(){
    int nc = N-1;
    vi S;
    while(nc >= 0){
        S.push_back(nc);
        nc = p[nc];
    }
    long long mf = MAX;
    reverse(S.begin(),S.end());
    for(int i=1;i<S.size();i++){
        int u = S[i-1], v = S[i];
        if(mm[u][v].first < mf) mf = mm[u][v].first;
    }
    if(D < mf)  mf = D;
    D -= mf;
    for(int i=1;i<S.size();i++){
        int u = S[i-1], v = S[i];
        mm[u][v].first -= mf;
        mm[v][u].first += mf;
        minT += mf * mm[u][v].second;
        // printf(" u,v = %d,%d, mf = %d, second = %d, minT = %ld\n",u,v,mf,mm[u][v].second, minT);
    }
}

int cnt[105];

int main(){
    while(cin >> N >> M){
        minT = 0;
        memset(mm,0,sizeof mm);
        int a,b; long long c;
        for(int i=0;i<M;i++){
            cin >> a >> b >> c;
            a--;b--;
            mm[a][b].second = c;  mm[b][a].second = -c;
            mm[a][b].first = mm[b][a].first = -1;
        }
        cin >> D >> K;
        for(int i=0;i<N;i++){
            for(int j=0;j<N;j++){
                if(mm[i][j].first == -1){
                    mm[i][j].first = K;
                }
            }
        }

        // then do the max-flow alg -- using dijkstra's to find the shortest path
        while(true){
            // init first
            for(int i=0;i<N;i++)    p[i] = -2;

            priority_queue<llll,vllll,greater<llll > > q;
            vll dist(N,MAX);

            q.push(llll(0,0));
            dist[0] = 0;

            memset(cnt,0,sizeof cnt);

            while(!q.empty()){
                int cc = q.top().first;
                int u = q.top().second;q.pop();
                if(cc > dist[u])    continue;

                if(u == N - 1)  break;  // avoid negative cycle

                cnt[u]++;
                if(cnt[u] > N)  break;
                dist[u] = cc;
                for(int i=0;i<N;i++){
                    int nd = mm[u][i].second + cc;
                    if(nd < dist[i] && mm[u][i].first > 0){
                        // printf(" u,i = %d, %d, mm[u][i] = %d\n",u,i,mm[u][i].first);
                        p[i] = u;
                        q.push(llll(nd,i));
                    }
                }
            }
            if(p[N-1] != -2){
                // printf("p[N-1] = %d\n",p[N-1]);
                augment();
            }
            else break;
            if(D <= 0)  break;
        }
        if(D > 0) cout << "Impossible." << endl;
        else cout << minT << endl;
    }
    return 0;
}
