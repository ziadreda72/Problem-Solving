#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

const int N = (int) 2e5 + 10;

int n , m , k;
vector < int > g[N];
int c[N];
bool vis[N];
map < int , int > mp;

void dfs(int u){
        vis[u] = 1;
        mp[c[u]]++;
        for(auto v : g[u]){
                if(vis[v])
                        continue;
                dfs(v);
        }
}

int32_t main() {
        ios::sync_with_stdio(false);cin.tie(nullptr);
        cout.tie(nullptr);cout.precision(20);
        cin >> n >> m >> k;
        for (int i = 0; i < n; ++i) {
                cin >> c[i];
        }
        while (m--){
                int u , v;
                cin >> u >> v;
                u-- , v--;
                g[u].push_back(v);
                g[v].push_back(u);
        }
        int ans = 0;
        for (int i = 0; i < n; ++i) {
                if(!vis[i]){
                        mp.clear();
                        dfs(i);
                        int mx = 0 , x;
                        for(auto [key , val] : mp){
                                if(val > mx){
                                        x = key;
                                        mx = val;
                                }
                        }
                        mp.erase(x);
                        for(auto [_ , val] : mp)
                                ans += val;
                }
        }
        cout << ans;
        return 0;
}
