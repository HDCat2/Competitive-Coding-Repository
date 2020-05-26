//Problem name in the file name
//Problem description can be found at: https://wcipeg.com/problem/ioi1121

#include <bits/stdc++.h>
using namespace std;

#define f first
#define s second

int dist[100010][2],N,M,K;
vector<pair<int, int>> G[100010];
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> PQ;

int main(){
    //freopen("input.txt","r",stdin);
    cin.sync_with_stdio(0); cin.tie(0);
    memset(dist, -1, sizeof dist);
    cin >> N >> M >> K;
    for(int i = 0; i < M; i++){
        int A,B,C;
        cin >> A >> B >> C;
        G[A].push_back({B,C});
        G[B].push_back({A,C});
    }
    for(int i = 0; i < K; i++){
        int A;
        cin >> A;
        dist[A][0] = 0;
        PQ.push({0,A});
    }
    while(!PQ.empty()){
        pair<int, int> u = PQ.top();
        PQ.pop();
        if(dist[u.s][0] == -1){
            dist[u.s][0] = u.f;
            continue;
        }
        if(dist[u.s][1] == -1){
            dist[u.s][1] = u.f;
            for(pair<int, int> i : G[u.s]){
                PQ.push({u.f + i.s, i.f});
            }
        }
    }
    cout << dist[0][1] << endl;
}
