//Problem description found at https://wcipeg.com/problem/ioi1022

#include <bits/stdc++.h>

using namespace std;

int n;
int val[1000010];
vector<int> adj[1000010];

int vv = 1e+9, ans;

int sz[1000010];
void comp(int u, int p = -1) {
    sz[u] = val[u];
    for (auto &v : adj[u]) if (v != p) {
        comp(v, u);
        sz[u] += sz[v];
    }
}
void dfs(int u, int x = 0, int p = -1) {
    int mx = x;
    for (auto &v : adj[u]) if (v != p) {
        dfs(v, x + sz[u] - sz[v], u);
        mx = max(mx, sz[v]);
    }
    if (mx < vv) {
        vv = mx;
        ans = u;
    }
}

int main() {
    //freopen("input.txt","r",stdin);
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> val[i];
    }
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    comp(0);
    dfs(0);
    cout << ans << endl;
}
