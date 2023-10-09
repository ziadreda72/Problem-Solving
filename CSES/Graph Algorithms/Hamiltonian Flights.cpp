#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

const int MOD = (int) 1e9 + 7;

int add(int a , int b){
        a %= MOD;
        b %= MOD;
        return (a + b) % MOD;
}

int32_t main(){
        ios::sync_with_stdio(false);
        cin.tie(nullptr);

        int N , M;
        cin >> N >> M;

        vector < vector < int > > g(N);
        while(M--){
                int u , v;
                cin >> u >> v;
                g[--u].push_back(--v);
        }

        vector dp(1 << N , vector < int > (N , 0));
        dp[1][0] = 1;
        for(int msk = 1 ; msk < (1 << N) ; ++msk){
                for(int u = 0 ; u < N ; ++u){
                        if(!((msk >> u) & 1) || dp[msk][u] == 0) continue;
                        for(auto v : g[u]){
                                if((msk >> v) & 1) continue;
                                int new_msk = msk | (1 << v);
                                dp[new_msk][v] = add(dp[new_msk][v] , dp[msk][u]);
                        }
                }
        }

        cout << dp[(1 << N) - 1][N - 1];

        return 0;
}
