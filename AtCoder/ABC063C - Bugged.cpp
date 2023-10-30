#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

int32_t main(){
        ios::sync_with_stdio(false);
        cin.tie(nullptr);

        int N;
        cin >> N;

        vector < int > a(N);
        for(int i = 0 ; i < N ; ++i) cin >> a[i];

        vector dp(N + 1 , vector < int > (10 , -1));

        dp[0][0] = 0;
        for(int i = 0 ; i < N ; ++i){
                for(int j = 0 ; j < 10 ; ++j){
                        if(dp[i][j] != -1){
                                dp[i + 1][j] = max(dp[i + 1][j] , dp[i][j]);
                                dp[i + 1][(j + a[i]) % 10] = max(dp[i + 1][(j + a[i]) % 10] , dp[i][j] + a[i]);
                        }
                }
        }

        int ans = 0;
        for(int i = 1 ; i < 10 ; ++i){
                ans = max(ans , dp[N][i]);
        }

        cout << ans;

        return 0;
}
