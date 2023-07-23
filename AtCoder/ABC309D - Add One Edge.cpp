#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

const int N = (int) 3e5 + 10 , inf = (int) 1e9;

int n , n2 , m;
vector < int > g[N];
vector < int > d(N , inf);

void bfs(int s){
        queue < int > q;
        d[s] = 0;
        q.push(s);
        while (!q.empty()){
                int u = q.front();
                q.pop();
                for(auto v : g[u]){
                        if(d[u] + 1 < d[v]){
                                d[v] = d[u] + 1;
                                q.push(v);
                        }
                }
        }
}

int32_t main() {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        cin >> n >> n2 >> m;
        while (m--){
                int u , v;
                cin >> u >> v;
                g[u].push_back(v);
                g[v].push_back(u);
        }
        bfs(1);
        bfs(n + n2);
        int mx = INT_MIN , mx2 = INT_MIN;
        for (int i = 1; i <= n; ++i) {
                mx = max(mx , d[i]);
        }
        for (int i = n + 1; i <= n + n2; ++i) {
                mx2 = max(mx2 , d[i]);
        }
        cout << mx + mx2 + 1;
        return 0;
}
