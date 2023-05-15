#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

#define F first
#define S second

int32_t main() {
    ios::sync_with_stdio(false);cin.tie(nullptr);
    cout.tie(nullptr);cout.precision(20);
    int n , m;
    cin >> n >> m;
    vector < vector < int > > g(n);
    vector < int > color(n , -1);
    while (m--){
        int u , v;
        cin >> u >> v;
        u-- , v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    queue < int > q;
    for (int i = 0; i < n; ++i) {
        if(color[i] == -1){
            color[i] = 0;
            q.push(i);
            while (!q.empty()){
                int u = q.front();
                q.pop();
                for(auto v : g[u]){
                    if(color[v] == -1){
                        color[v] = color[u] ^ 1;
                        q.push(v);
                    }else{
                        if(color[v] == color[u]){
                            cout << -1;
                            return 0;
                        }
                    }
                }
            }
        }
    }
    vector < vector < int > > ans(2);
    for (int i = 0; i < n; ++i) {
        ans[color[i]].push_back(i + 1);
    }
    for(auto v : ans){
        cout << v.size() << '\n';
        for(auto x : v)
            cout << x << ' ';
        cout << '\n';
    }
    return 0;
}
