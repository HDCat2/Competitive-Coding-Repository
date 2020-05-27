//Problem description found at https://wcipeg.com/problem/ccoqr16p2

#include <bits/stdc++.h>
using namespace std;

#define f first
#define s second

vector<int> R[100010];
int dists[100010];
int ad[100010];
int N,K,Q,v;
map<pair<int, int>, pair<int, int>> G;
map<pair<int, int>, bool> visited;

int main(){
    //freopen("input.txt","r",stdin);
    cin.sync_with_stdio(0); cin.tie();
    cin >> N;
    for(int i = 1; i <= N; i++){
        cin >> K;
        for(int q = 0; q < K; q++){
            cin >> v;
            R[i].push_back(v);
            if(q>0){
                G[{R[i][q],i}] = {i,R[i][q-1]};
            }
        }
        G[{R[i][0],i}] = {i,R[i][K-1]};
    }
    cin >> Q;
    for(int qwer = 0; qwer < Q; qwer++){
        cin >> v;
        for(int i = 0; i < R[v].size(); i++){
            if(not visited[{v,R[v][i]}]){
                pair<int,int> startpoint = {v,R[v][i]},lel = {v,R[v][i]};
                vector<int> pathing;
                while(true){
                    pathing.push_back(lel.f);
                    visited[lel] = true;
                    lel = G[lel];
                    if(lel == startpoint) break;
                }
                int meow = pathing.size();
                for(int q = 0; q < meow; q++){
                    pathing.push_back(pathing[q]);
                }
                for(int q = 0; q < pathing.size(); q++){
                    if(ad[pathing[q]] > q) ad[pathing[q]] = q;
                    else{
                        dists[pathing[q]] = max(dists[pathing[q]], abs(ad[pathing[q]] - q));
                        ad[pathing[q]] = q;
                    }
                }
            }
        }
        cout << dists[v] << endl;
    }
    return 0;
}
