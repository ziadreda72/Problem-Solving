#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

#define F first
#define S second

int n , m;
vector < vector < int > > g;
vector < int > color;

int32_t main() {
    ios::sync_with_stdio(false);cin.tie(nullptr);
    cout.tie(nullptr);cout.precision(20);
    cin >> n >> m;
    g = vector < vector < int > > (n);
    color.assign(n , -1);
    while (m--){
        int u , v;
        cin >> u >> v;
        u-- , v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    queue < int > q;
    bool ans = true;
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
                        ans &= color[u] != color[v];
                    }
                }
            }
        }
    }
    cout << (ans ? "Bipartite\n" : "Bipartiteness Check Failed\n");
    return 0;
}
