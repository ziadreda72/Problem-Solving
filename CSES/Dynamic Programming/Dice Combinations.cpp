#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

const int MOD = (int) 1e9 + 7;

int32_t main(){
        ios::sync_with_stdio(false);
        cin.tie(nullptr);

        int n;
        cin >> n;

        vector < i64 > dp(n + 1 , 0);
        dp[0] = 1;
        for(int i = 0 ; i < n ; ++i){
                for(int j = 1 ; j <= 6 && i + j <= n ; ++j){
                        dp[i + j] += dp[i];
                        dp[i + j] %= MOD;
                }
        }

        cout << dp[n];

        return 0;
}
