#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

int32_t main() {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        int n , P;
        cin >> n >> P;
        vector < long double > p(n);
        for (int i = 0; i < n; ++i) {
                int l , r;
                cin >> l >> r;
                int cnt = r / P - ((l - 1) / P);
                p[i] = (long double) cnt / (1.0 * (r - l + 1));
        }
        long double ans = 0;
        for (int i = 0; i < n; ++i) {
                int j = (i + 1) % n;
                ans += p[i] * 2000 + (1 - p[i]) * p[j] * 2000;
        }
        cout << setprecision(20) << ans;
        return 0;
}
