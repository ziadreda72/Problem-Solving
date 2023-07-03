#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

const int N = (int) 1e5 + 10;

int n;
vector < int > g[N];
int color[N] , dp[N];

void dfs(int u , int par = -1){
        dp[u] = color[u];
        for(auto v : g[u]){
                if(v == par)
                        continue;
                dfs(v , u);
                dp[u] += dp[v];
        }
}

int32_t main() {
        ios::sync_with_stdio(false);cin.tie(nullptr);
        cout.tie(nullptr);cout.precision(20);
        cin >> n;
        for (int i = 0; i < n - 1; ++i) {
                int u , v , t;
                cin >> u >> v >> t;
                t--;
                g[u].push_back(v);
                g[v].push_back(u);
                if(t)
                        color[u] = color[v] = 1;
        }
        dfs(1);
        vector < int > ans;
        for (int i = 1; i <= n; ++i) {
                if(color[i] && dp[i] == 1)
                        ans.push_back(i);
        }
        cout << ans.size() << '\n';
        for(auto x : ans)
                cout << x << ' ';
        return 0;
}
