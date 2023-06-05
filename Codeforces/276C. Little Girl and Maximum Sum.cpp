#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

int32_t main() {
        ios::sync_with_stdio(false);cin.tie(nullptr);
        cout.tie(nullptr);cout.precision(20);
        int n , q;
        cin >> n >> q;
        vector < int > a(n);
        for (int i = 0; i < n; ++i) {
                cin >> a[i];
        }
        vector < int > par(n);
        while (q--){
                int l , r;
                cin >> l >> r;
                l-- , r--;
                par[l]++;
                if(r + 1 < n)
                        par[r + 1]--;
        }
        for (int i = 1; i < n; ++i) {
                par[i] += par[i - 1];
        }
        sort(par.begin(), par.end());
        sort(a.begin(), a.end());
        i64 ans = 0;
        for (int i = 0; i < n; ++i) {
                ans += 1LL * a[i] * par[i];
        }
        cout << ans;
        return 0;
}
