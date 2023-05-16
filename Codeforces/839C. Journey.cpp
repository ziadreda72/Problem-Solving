#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

#define F first
#define S second

int n;
vector < vector < int > > g;
vector < int > vis , d;
vector < double > prob;

void dfs(int u){
    vis[u] = 1;
    if(g[u].size() == 1)
        return;
    double x = (double) g[u].size() - 1;
    double p = 1 / x;
    for(auto v : g[u]){
        if(!vis[v]){
            prob[v] = prob[u] * p;
            d[v] = d[u] + 1;
            dfs(v);
        }
    }
}

int32_t main() {
    ios::sync_with_stdio(false);cin.tie(nullptr);
    cout.tie(nullptr);cout.precision(20);
    cin >> n;
    if(n == 1){
        cout << 0;
        return 0;
    }
    g = vector < vector < int > > (n);
    vis.assign(n , 0);
    d.assign(n , 0);
    prob.resize(n);
    for (int i = 0; i < n - 1; ++i) {
        int u , v;
        cin >> u >> v;
        u-- , v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    vis[0] = 1;
    double x = (double) g[0].size();
    double p = 1 / x;
    for(auto i : g[0]){
        d[i] = 1;
        prob[i] = p;
        dfs(i);
    }
    double ans = 0;
    for (int i = 1; i < n; ++i) {
        if(g[i].size() == 1)
            ans += d[i] * prob[i];
    }
    cout << ans;
    return 0;
}
