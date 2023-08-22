#include <bits/stdc++.h>

using namespace std;
using i64 = long long;
using i128 = __int128;
using ld = long double;

#define F first
#define S second

const int N = (int) 2e5 + 5;

int n , m;
vector < int > g[N];
bool vis[N];
int V , E;

void dfs(int u){
        vis[u] = 1;
        ++V;
        E += (int) g[u].size();
        for(int v : g[u]){
                if(vis[v])
                        continue;
                dfs(v);
        }
}

int32_t main(){
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        cin >> n >> m;
        while(m--){
                int u , v;
                cin >> u >> v;
                g[u].push_back(v);
                g[v].push_back(u);
        }
        int ans = 0;
        for(int i = 1 ; i <= n ; ++i){
                if(vis[i])
                        continue;
                V = E = 0;
                dfs(i);
                E >>= 1;
                ans += (E - (V - 1));
        }
        cout << ans;
        return 0;
}
