#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

int32_t main(){
        ios::sync_with_stdio(false);
        cin.tie(nullptr);

        const int INF = (int) 1e9;

        int N;
        cin >> N;

        vector < int > dp(N + 1 , INF);

        dp[0] = 0;
        for(int i = 0 ; i < N ; ++i){
                for(int x = 1 ; i + x <= N ; x *= 6){
                        dp[i + x] = min(dp[i + x] , dp[i] + 1);
                }
                for(int x = 1 ; i + x <= N ; x *= 9){
                        dp[i + x] = min(dp[i + x] , dp[i] + 1);
                }
        }

        cout << dp[N];

        return 0;
}
