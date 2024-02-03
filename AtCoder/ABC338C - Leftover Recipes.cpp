#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

int32_t main(){
        ios::sync_with_stdio(false);
        cin.tie(nullptr);

        int n;
        cin >> n;

        vector < int > q(n);
        for (int i = 0 ; i < n ; ++i) cin >> q[i];

        vector < int > a(n);
        for (int i = 0 ; i < n ; ++i) cin >> a[i];

        vector < int > b(n);
        for (int i = 0 ; i < n ; ++i) cin >> b[i];

        auto good = [&](int k) {
                bool ret = 0;
                for (int i = 0 ; i <= k ; ++i) {
                        bool ok = 1; 
                        for (int j = 0 ; j < n ; ++j) {
                                if (a[j] != 0) {
                                        ok &= (q[j] / a[j]) >= i;
                                }
                                if (b[j] != 0) {
                                        ok &= ((q[j] - (a[j] * i)) / b[j]) >= (k - i);
                                }
                        }
                        ret |= ok;
                }
                return ret;
        };

        int lo = 0 , hi = (int) 2e6 + + 100;
        while (hi - lo > 1) {
                int mid = (lo + hi) / 2;
                if (good(mid)) {
                        lo = mid;
                } else {
                        hi = mid;
                } 
        }

        cout << lo;

        return 0;
}
