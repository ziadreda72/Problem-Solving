#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

#define F first
#define S second

int n , m;
vector < vector < int > > g , g2;
vector < int > a , vis , vis2;

int dfs(int u , int st){
    vis[u] = 1;
    int ret = 0;
    if(u != st) ret += a[u];
    for(auto v : g[u]){
        if(!vis[v]) ret += dfs(v , st);
    }
    return ret;
}

int dfs2(int u){
    int ret = 0;
    vis2[u] = 1;
    ret += a[u];
    for(auto v : g2[u]){
        if (!vis2[v]) ret += dfs2(v);
    }
    return ret;
}

int32_t main() {
    ios::sync_with_stdio(false);cin.tie(nullptr);
    cout.tie(nullptr);cout.precision(20);
    int t = 1;
    while (cin >> n >> m && n){
        g = vector < vector < int > > (n);
        g2 = vector < vector < int > > (n);
        a = vector < int > (n);
        int tot = 0;
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
            tot += a[i];
        }
        while (m--){
            int u , v;
            cin >> u >> v;
            u-- , v--;
            g[u].push_back(v);
            g2[v].push_back(u);
        }
        int q;
        cin >> q;
        cout << "Case #" << t++ << ":\n";
        while (q--){
            int x;
            cin >> x;
            x--;
            vis = vector < int > (n , 0);
            int mn = dfs(x , x);
            vis2 = vector < int > (n , 0);
            int mx = tot - dfs2(x);
            cout << abs(mx - mn) << '\n';
        }
        cout << '\n';
    }
    return 0;
}
