#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

int32_t main() {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        int n , m;
        cin >> n >> m;
        vector < double > a(n);
        for (int i = 0; i < n; ++i) {
                cin >> a[i];
        }
        long double ans = 0;
        while (m--){
                int u , v , w;
                cin >> u >> v >> w;
                u-- , v--;
                ans = max(ans , (long double) (a[u] + a[v]) / (1.0 * w));
        }
        cout << setprecision(20) << ans;
        return 0;
}
