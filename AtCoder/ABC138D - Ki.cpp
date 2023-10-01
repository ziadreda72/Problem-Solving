#include <bits/stdc++.h>

using namespace std;

const int MAX = (int) 2e5 + 5;

int N , Q;
vector < int > g[MAX];
int dp[MAX];

void dfs(int u , int par = 0){
        dp[u] += dp[par];
        for(int v : g[u]){
                if(v == par) continue;
                dfs(v , u);
        }
}

int32_t main(){
        ios::sync_with_stdio(false);
        cin.tie(nullptr);

        cin >> N >> Q;

        for(int i = 0 ; i + 1 < N ; ++i){
                int u , v;
                cin >> u >> v;
                g[u].push_back(v);
                g[v].push_back(u);
        }

        while(Q--){
                int p , x;
                cin >> p >> x;
                dp[p] += x;
        }
        
        dfs(1);

        for(int i = 1 ; i <= N ; ++i) cout << dp[i] << ' ';

        return 0;
}
