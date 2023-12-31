#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

int32_t main(){
        ios::sync_with_stdio(false);
        cin.tie(nullptr);

        int n;
        cin >> n;

        vector dp(n , vector < i64 > (n));
        for (int i = 0 ; i < n ; ++i) {
                for (int j = 0 ; j < n ; ++j) {
                        cin >> dp[i][j];
                }
        } 

        vector < int > x(n);
        for (int i = 0 ; i < n ; ++i) cin >> x[i] , --x[i];

        vector < bool > vis(n , 0);
        vector < i64 > ans;

        while (!x.empty()) {
                auto k = x.back();
                x.pop_back();
                vis[k] = 1;

                for (int i = 0 ; i < n ; ++i) {
                        for (int j = 0 ; j < n ; ++j) {
                                dp[i][j] = min(dp[i][j] , dp[i][k] + dp[k][j]);
                        }
                }

                i64 S = 0;
                for (int i = 0 ; i < n ; ++i) {
                        if (!vis[i]) continue;
                        for (int j = 0 ; j < n ; ++j) {
                                if (!vis[j]) continue;
                                S += dp[i][j];
                        }
                }
                ans.push_back(S);
        }

        while (!ans.empty()) {
                cout << ans.back() << ' ';
                ans.pop_back();
        }

        return 0;
}
