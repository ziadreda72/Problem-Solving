#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

const int MOD = 998244353 , MAX = (int) 1e5;

int32_t main(){
        ios::sync_with_stdio(false);
        cin.tie(nullptr);

        int n;
        cin >> n;

        vector < i64 > cnt(MAX) , a(n);
        for (int i = 0 ; i < n ; ++i) {
                cin >> a[i];

                if (i == 0) {
                        if (a[i] != 0) {
                                cout << 0;
                                return 0;
                        }
                }else {
                        if (a[i] == 0) {
                                cout << 0;
                                return 0;
                        }
                }

                ++cnt[a[i]];
        }

        i64 ans = 1;
        for (int i = 1 ; i < n ; ++i) {
                ans = 1LL * ans * cnt[a[i] - 1];
                ans %= MOD;
        }

        cout << ans;

        return 0;
}
