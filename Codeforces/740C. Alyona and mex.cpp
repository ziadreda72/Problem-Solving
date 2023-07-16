#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

int32_t main() {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        int n , m;
        cin >> n >> m;
        int ans = INT32_MAX;
        while (m--){
                int l , r;
                cin >> l >> r;
                ans = min(ans , r - l + 1);
        }
        cout << ans << '\n';
        for (int i = 0; i < n; ++i) {
                cout << i % ans << ' ';
        }
        return 0;
}
