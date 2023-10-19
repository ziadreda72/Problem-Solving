#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

const int MAX = (int) 2e5 + 10;

int N , M;
vector < int > g[MAX];
bool vis[MAX];
int ans;

void dfs(int u){
        ans++;
        if(ans >= (int) 1e6){
                cout << (int) 1e6;
                exit(0);
        }
        
        for(auto v : g[u]){
                if(vis[v]) continue;
                vis[v] = 1;
                dfs(v);
                vis[v] = 0;
        }
}

int32_t main(){
        ios::sync_with_stdio(false);
        cin.tie(nullptr);

        cin >> N >> M;

        while(M--){
                int u , v;
                cin >> u >> v;
                g[u].push_back(v);
                g[v].push_back(u);
        }

        vis[1] = 1;
        dfs(1);

        cout << ans;

        return 0;
}
