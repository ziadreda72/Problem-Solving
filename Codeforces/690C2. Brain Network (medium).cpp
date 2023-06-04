#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

int32_t main() {
        ios::sync_with_stdio(false);cin.tie(nullptr);
        cout.tie(nullptr);cout.precision(20);
        int n , m;
        cin >> n >> m;
        vector < vector < int > > g(n);
        for (int i = 0; i < m; ++i) {
                int u , v;
                cin >> u >> v;
                u-- , v--;
                g[u].push_back(v);
                g[v].push_back(u);
        }
        auto bfs = [&](int s){
                queue < int > q;
                vector < int > d(n , -1);
                d[s] = 0;
                q.push(s);
                while (!q.empty()){
                        int u = q.front();
                        q.pop();
                        for(auto v : g[u]){
                                if(d[v] == -1){
                                        d[v] = d[u] + 1;
                                        q.push(v);
                                }
                        }
                }
                return d;
        };
        auto d0 = bfs(0);
        int x = max_element(d0.begin(), d0.end()) - d0.begin();
        auto d1 = bfs(x);
        cout << *max_element(d1.begin(), d1.end());
        return 0;
}
