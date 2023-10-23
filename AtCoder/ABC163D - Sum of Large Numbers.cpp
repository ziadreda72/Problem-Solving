#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

int32_t main(){
        ios::sync_with_stdio(false);
        cin.tie(nullptr);

        const int MOD = (int) 1e9 + 7;

        i64 N , K;
        cin >> N >> K;

        i64 ans = 0;
        for(i64 k = K ; k <= N + 1 ; ++k){
                i64 L = 1LL * k * (k - 1) / 2;
                i64 R = 1LL * k * (2 * N - k + 1) / 2;
                ans += R - L + 1;
                ans %= MOD;
        }

        cout << ans;

        return 0;
}
