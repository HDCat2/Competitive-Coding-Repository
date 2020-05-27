//Problem description found at https://wcipeg.com/problem/ccc14s2p3

#include <bits/stdc++.h>
using namespace std;
int N, W, M;
long long dp[210][210][2];
vector <pair<int,char>> adj[210];
bool root[210];

void dfs(int cur){
    dp[cur][0][0] = 1; // no werewolf and cur is citizen
    dp[cur][1][1] = 1; // one werewolf and cur is werewolf
    for (int a = 0; a < adj[cur].size(); a++){
        int nex = adj[cur][a].first;
        char tt = adj[cur][a].second;
        dfs(nex);
        for (int j = W; j >=0; j--) // how many werewolf at cur
        {
            long long is_w = 0, not_w = 0;
            for (int k = 0; k <= j; k++) // how many werewold in children of cur
            {
                // if cur is a civilian
                not_w += dp[cur][j-k][0] * (dp[nex][k][0] + dp[nex][k][1]);
                not_w %= 1000000007;
                // if cur is a werewolf
                if (tt == 'A')
                    is_w += dp[cur][j-k][1] * dp[nex][k][0];
                else
                    is_w += dp[cur][j-k][1] * dp[nex][k][1];
                is_w %= 1000000007;
            }
            dp[cur][j][0] = not_w;
            dp[cur][j][1] = is_w;
        }
    }
}
int main(){
    //freopen("input.txt","r",stdin);
    cin >> N >> W >> M;
    for (int i = 0; i < M; i++)
    {
        char o;
        int a, b;
        cin>>o>>a>>b;
        root[b] = true;
        adj[a].push_back({b,o});
    }
    for (int i = 1; i <= N; i++)
    {
        if (!root[i])
            adj[0].push_back({i,'D'});
    }
    dfs(0);
    cout << dp[0][W][0] % 1000000007 << endl;
}
