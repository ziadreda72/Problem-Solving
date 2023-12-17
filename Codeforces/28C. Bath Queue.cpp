#include <bits/stdc++.h>

using namespace std;
using i64 = long long;
using ld = long double;

const int MAX = 55;

int N , M;
i64 a[MAX] , C[MAX + 1][MAX + 1];
ld dp[MAX][MAX][MAX];
bool vis[MAX][MAX][MAX];

ld solve(int i = 0 , int j = N , i64 mx = 0) {
        if (i >= M) {
                return j == 0 ? mx : 0;
        }

        auto &ret = dp[i][j][mx];
        if (vis[i][j][mx]) {
                return ret;
        }
        vis[i][j][mx] = 1;

        ret = (ld) 0.0;

        ld p = (ld) 1.0;

        for (int k = 0 ; k <= j ; ++k) {
                ret += (ld) p * C[j][k] * solve(i + 1 , j - k , max(mx , (k + a[i] - 1) / a[i]));
                p /= (ld) M;
        }

        return ret;
}

int32_t main() {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);

        C[0][0] = 1;
        for (int n = 1 ; n <= MAX ; ++n) {
                C[n][0] = C[n][n] = 1;
                for (int k = 1 ; k < n ; ++k)
                        C[n][k] = C[n - 1][k - 1] + C[n - 1][k];
        }

        cin >> N >> M;

        for (int i = 0 ; i < M ; ++i) cin >> a[i];

        cout << fixed << setprecision(20) << solve();

        return 0;
}
