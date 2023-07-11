#include <bits/stdc++.h>

using namespace std;

using i64 = long long;
using ld = long double;

void solveTC() {
        int n;
        ld d , h;
        cin >> n >> d >> h;
        vector < ld > y(n);
        for (int i = 0; i < n; ++i) {
                cin >> y[i];
        }
        ld ans = 0;
        for (int i = 0; i + 1 < n; ++i) {
                ans += d * h / 2;
                if(y[i] + h > y[i + 1]){
                        ld h2 = (y[i] + h) - y[i + 1];
                        ld d2 = d - ((y[i + 1] - y[i]) * d / h);
                        ans -= h2 * d2 / 2;
                }
        }
        ans += d * h / 2;
        cout << ans;
}

int32_t main() {
        ios::sync_with_stdio(false);cin.tie(nullptr);
        cout.tie(nullptr);cout.precision(20);
        int tc = 1;
        cin >> tc;
        while(tc--){
                solveTC();
                cout << '\n';
        }
        return 0;
}
