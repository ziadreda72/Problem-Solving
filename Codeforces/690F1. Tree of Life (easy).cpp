#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

const int OO = INT32_MAX;

int ans;
vector < vector < int > > g;
vector < bool > vis;

void dfs(int u , int c){
        vis[u] = 1;
        if(c == 2){
                ans++;
                return;
        }
        for(auto v : g[u]){
                if(!vis[v])
                        dfs(v , c + 1);
        }
}

int32_t main() {
        ios::sync_with_stdio(false);cin.tie(nullptr);
        cout.tie(nullptr);cout.precision(20);
        int n;
        cin >> n;
        g = vector < vector < int > > (n);
        for (int i = 0; i < n - 1; ++i) {
                int u , v;
                cin >> u >> v;
                u-- , v--;
                g[u].push_back(v);
                g[v].push_back(u);
        }
        for (int i = 0; i < n; ++i) {
                vis = vector < bool > (n , 0);
                dfs(i , 0);
        }
        ans /= 2;
        cout << ans;
        return 0;
}
