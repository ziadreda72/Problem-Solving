#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

#define F first
#define S second

int n;
vector < vector < int > > g;
vector < int > c , vis;
int ans;

void dfs(int u){
    vis[u] = true;
    for(auto v : g[u]){
        if(!vis[v]){
            if(c[u] != c[v]) ans++;
            dfs(v);
        }
    }
}

int32_t main() {
    ios::sync_with_stdio(false);cin.tie(nullptr);
    cout.tie(nullptr);cout.precision(20);
    cin >> n;
    c.resize(n + 1);
    g.resize(n + 1);
    vis.assign(n + 1 , 0);
    ans = 1;
    for (int i = 2; i <= n; ++i) {
        int p;
        cin >> p;
        g[p].push_back(i);
        g[i].push_back(p);
    }
    for (int i = 1; i <= n; ++i) {
        cin >> c[i];
    }
    dfs(1);
    cout << ans;
    return 0;
}
