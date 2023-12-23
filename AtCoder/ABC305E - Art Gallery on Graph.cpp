#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

int32_t main(){
        ios::sync_with_stdio(false);
        cin.tie(nullptr);

        int n , m , k;
        cin >> n >> m >> k;

        vector < vector < int > > g(n);
        while (m--) {
                int u , v;
                cin >> u >> v;
                --u , --v;
                g[u].push_back(v);
                g[v].push_back(u);
        }

        priority_queue < pair < int , int > > pq;
        while (k--) {
                int p , h;
                cin >> p >> h;
                pq.emplace(h , --p);
        }

        vector < bool > vis(n);
        
        set < int > ans;

        while (!pq.empty()) {
                auto [h , u] = pq.top();
                pq.pop();
                ans.insert(u + 1);
                if (vis[u] || h == 0) continue;
                vis[u] = 1;
                for (auto v : g[u]) {
                        pq.emplace(h - 1 , v);
                }
        }

        cout << ans.size() << '\n';
        for(auto i : ans) cout << i << ' ';

        return 0;
}
