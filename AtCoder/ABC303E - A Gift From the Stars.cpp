#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

int n;
vector < vector < int > > g;
vector < int > ans;

void dfs(int u , int par , int dep = 0) {
        if (dep % 3 == 0) ans.push_back(g[u].size());
        for (auto v : g[u]) {
                if (v == par) continue;
                dfs(v , u , dep + 1);
        } 
}

int32_t main(){
        ios::sync_with_stdio(false);
        cin.tie(nullptr);

        cin >> n;
        
        g.resize(n);
        for (int i = 0 ; i + 1 < n ; ++i) {
                int u , v;
                cin >> u >> v;
                --u , --v;
                g[u].push_back(v);
                g[v].push_back(u);
        }

        for (int i = 0 ; i < n ; ++i) {
                if (g[i].size() == 1) {
                        dfs(g[i][0] , i);
                        break;
                }
        }

        sort(ans.begin() , ans.end());

        for (auto i : ans) cout << i << ' ';

        return 0;
}
