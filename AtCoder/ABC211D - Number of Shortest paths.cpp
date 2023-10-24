#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

int32_t main(){
        ios::sync_with_stdio(false);
        cin.tie(nullptr);

        const int INF = (int) 1e9 , MOD = (int) 1e9 + 7;

        int N , M;
        cin >> N >> M;

        vector < vector < int > > g(N + 1);
        while(M--){
                int u , v;
                cin >> u >> v;

                g[u].push_back(v);
                g[v].push_back(u);
        }

        vector < int > d(N + 1 , INF);
        d[1] = 0;

        queue < int > q;
        q.push(1);

        while(!q.empty()){
                int u = q.front();
                q.pop();

                for(auto v : g[u]){
                        if(d[u] + 1 < d[v]){
                                d[v] = d[u] + 1;
                                q.push(v);
                        }
                }
        }

        vector < i64 > dp(N + 1 , 0);
        dp[1] = 1;
        
        vector < bool > vis(N + 1 , 0);

        q.push(1);
        while(!q.empty()){
                int u = q.front();
                q.pop();

                if(vis[u]){
                     continue;   
                }

               vis[u] = 1;

                for(auto v : g[u]){
                        if(d[u] + 1 == d[v]){
                                dp[v] += dp[u];
                                dp[v] %= MOD;
                                q.push(v);
                        }
                }
        }

        cout << dp[N];

        return 0;
}
