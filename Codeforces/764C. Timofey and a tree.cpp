#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

#define F first
#define S second

int n;
vector < pair < int , int > > edges;
vector < int > c;
vector < vector < int > > g;

bool dfs(int u , int par , int C){
    bool ret = c[u] == C;
    for(auto v : g[u]){
        if(v == par)
            continue;
        ret &= dfs(v , u , C);
    }
    return ret;
}

bool solve(int root){
    bool ret = 1;
    for(auto v : g[root]){
        ret &= dfs(v , root , c[v]);
    }
    return ret;
}

int32_t main() {
    ios::sync_with_stdio(false);cin.tie(nullptr);
    cout.tie(nullptr);cout.precision(20);
    cin >> n;
    c.resize(n);
    g.resize(n);
    for (int i = 0; i < n - 1; ++i) {
        int u , v;
        cin >> u >> v;
        u-- , v--;
        g[u].push_back(v);
        g[v].push_back(u);
        edges.emplace_back(u , v);
    }
    for (int i = 0; i < n; ++i) {
        cin >> c[i];
    }
    int r = -1 , r2;
    for(auto [u , v] : edges){
        if(c[u] != c[v])
            r = u , r2 = v;
    }
    if(r == -1){
        cout << "YES\n1";
        return 0;
    }
    bool res = solve(r);
    bool res2 = solve(r2);
    if(res){
        cout << "YES\n" << r + 1;
    }else if(res2){
        cout << "YES\n" << r2 + 1;
    }else{
        cout << "NO";
    }
    return 0;
}
