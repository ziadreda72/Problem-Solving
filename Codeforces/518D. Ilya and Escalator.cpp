#include <bits/stdc++.h>

using namespace std;
using i64 = long long;
using ld = long double;


int32_t main(){
        ios::sync_with_stdio(false);
        cin.tie(nullptr);

        int n;
        cin >> n;

        ld p;
        cin >> p;

        int t;
        cin >> t;

        vector dp(n + 1 , vector < ld > (t + 1 , (ld) 0.0));

        dp[0][0] = (ld) 1.0;
        for(int i = 0 ; i < n ; ++i){
                for(int j = 0 ; j < t ; ++j){
                        dp[i + 1][j + 1] += (ld) dp[i][j] * p;
                        dp[i][j + 1] += (ld) dp[i][j] * ((ld) 1.0 - p);
                }
        }

        ld ans = 0.0;
        for(int i = 0 ; i < n ; ++i){
                ans += (ld) dp[i][t] * i;
        }

        ld sum = 0.0;
        for(int i = 0 ; i <= t ; ++i) sum += dp[n][i];

        ans += (ld) sum * n;

        cout << fixed << setprecision(20) << ans;

        return 0;
}
