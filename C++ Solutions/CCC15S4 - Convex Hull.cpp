//Problem description found at https://wcipeg.com/problem/ccc15s4

#include <bits/stdc++.h>
using namespace std;

int K,N,M, V1, V2, C, D, S, E, v, d, c;
int dist[2010];
int cost[2010];
priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> Q;
map<int, vector<vector<int>>> graph;
int main(){
    //freopen("input.txt","r",stdin);
    for(int i = 0; i < 2010; i++){
        dist[i] = dist[i] = 20000050;
    }
    cin >> K >> N >> M;
    for(int i = 0; i < M; i++){
        cin >> V1 >> V2 >> D >> C;
        graph[V1-1].push_back({C, V2-1, D});
        graph[V2-1].push_back({C, V1-1, D});
    }

    cin >> S >> E;

    Q.push({0,S-1,0});
    while(!Q.empty()){
        vector<int> cat = Q.top();
        Q.pop();
        v = cat[1];
        d = cat[2];
        c = cat[0];

        if(d < dist[v]){
            dist[v] = d;
            cost[v] = c;
            for(int i = 0; i < graph[v].size(); i++){
                if((c + graph[v][i][0]) < K){
                    Q.push({c + graph[v][i][0], graph[v][i][1], graph[v][i][2] + d});
                }
            }
        }
    }

    if(dist[E-1] == 20000050){
        cout << -1;
    }
    else{
        cout << dist[E-1];
    }

    return 0;
}
