#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

int32_t main() {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        int n;
        cin >> n;
        vector < int > a(n);
        for (int i = 0; i < n; ++i) {
                cin >> a[i];
        }
        sort(a.rbegin(), a.rend());
        vector < i64 > pref(n);
        pref[0] = a[0];
        for (int i = 1; i < n; ++i) {
                pref[i] += pref[i - 1] + a[i];
        }
        i64 ans = 0;
        int x = 1;
        while (x <= n)
                ans += pref[x - 1] , x *= 4;
        cout << ans;
        return 0;
}
