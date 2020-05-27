//Problem description found at https://wcipeg.com/problem/ccc11s2p2

#include <bits/stdc++.h>
using namespace std;

#define f first
#define s second

int S,N,E,es,t,d,u,V,D,C;
int dist[1605], cost[1605];
priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> Q;
map<int, vector<pair<pair<int, int>,int>>> G;

int main(){
    //freopen("input.txt","r",stdin);
    for(int i = 0; i < 1605; i++) dist[i] = 16000001;
    cin >> S >> N >> E;
    for(int i = 0; i < E; i++){
        cin >> es >> t >> d >> u;
        if(u){
            G[es].push_back({{d,t},d});
            G[t].push_back({{d,es},d});
        }
        else{
            G[es].push_back({{d,t},0});
            G[t].push_back({{d,es},0});
        }
    }

    Q.push({0, {0,0}});

    while(!Q.empty()){
        pair<int, pair<int, int>> c = Q.top();
        Q.pop();

        V = c.s.f;
        D = c.s.s;
        C = c.f;

        if(D < dist[V]){
            dist[V] = D;
            cost[V] = C;
            for(int i = 0; i < G[V].size(); i++){
                if((C + G[V][i].s) <= S){
                    Q.push({C + G[V][i].s, {G[V][i].f.s, G[V][i].f.f + D}});
                }
            }
        }
    }

    if(dist[N-1] >= 16000001){
        cout << -1;
        return 0;
    }

    cout << dist[N-1] << endl;

}
