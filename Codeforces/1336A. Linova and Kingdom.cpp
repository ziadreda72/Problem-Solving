#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

const int N = (int) 2e5 + 10;

int n , k;
int sz[N] , color[N];
vector < int > g[N];
vector < pair < int , int > > mx;
i64 ans;

void dfs(int u , int par , int lvl){
        sz[u] = 1;
        for(auto v : g[u]){
                if(v == par)
                        continue;
                dfs(v , u , lvl + 1);
                sz[u] += sz[v];
        }
        mx.emplace_back(sz[u] - lvl , u);
}

void dfs2(int u , int par , i64 cost){
        if(!color[u])
                ans += cost;
        for(auto v : g[u]){
                if(v == par)
                        continue;
                dfs2(v , u , 1LL * (cost + color[u]));
        }
}

int32_t main() {
        ios::sync_with_stdio(false);cin.tie(nullptr);
        cout.tie(nullptr);cout.precision(20);
        cin >> n >> k;
        for (int i = 0; i + 1 < n; ++i) {
                int u , v;
                cin >> u >> v;
                g[u].push_back(v);
                g[v].push_back(u);
        }
        dfs(1 , -1 , 0);
        sort(mx.rbegin(), mx.rend());
        for (int i = 0; i < n - k; ++i) {
                color[mx[i].second] = 1;
        }
        dfs2(1 , -1 , 0);
        cout << ans;
        return 0;
}
