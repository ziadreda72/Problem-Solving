#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

const int INF = INT32_MAX;

int32_t main(){
        ios::sync_with_stdio(false);
        cin.tie(nullptr);

        int n;
        cin >> n;

        vector < int > a(n);
        for (int i = 0 ; i < n ; ++i) cin >> a[i];

        vector dp(n , vector < int > (n , INF));
        vector dp2(n , vector < i64 > (n , 0LL));

        for (int i = 0 ; i < n ; ++i) dp[i][i] = 0;

        for (int i = 0 ; i < n ; ++i) {
                for (int j = 0 ; j < n ; ++j) {
                        char c;
                        cin >> c;
                        if (c == 'Y') {
                                dp[i][j] = 1;
                                dp2[i][j] = a[i] + a[j];
                        }else {
                                dp[i][j] = INF;
                        }
                }
        }

        for (int k = 0 ; k < n ; ++k) {
                for (int i = 0 ; i < n ; ++i) {
                        for (int j = 0 ; j < n ; ++j) {
                                if (dp[i][k] < INF && dp[k][j] < INF) {
                                        if (dp[i][j] > dp[i][k] + dp[k][j]) {
                                                dp[i][j] = dp[i][k] + dp[k][j];
                                                dp2[i][j] = dp2[i][k] + dp2[k][j] - a[k];
                                        } else if (dp[i][j] == (dp[i][k] + dp[k][j])) {
                                                dp2[i][j] = max(dp2[i][j] , dp2[i][k] + dp2[k][j] - a[k]);
                                        }
                                }
                        }
                }
        }

        int Q;
        cin >> Q;

        while (Q--) {
                int u , v;
                cin >> u >> v;
                --u , --v;
                if (dp[u][v] == INF) {
                        cout << "Impossible\n";
                }else {
                        cout << dp[u][v] << ' ' << dp2[u][v] << '\n';
                }
        }

        return 0;
}
