#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

void solveTC(){
        int n;
        cin >> n;

        vector < int > cnt(n + 1);
        for (int i = 0 ; i < n ; ++i) {
                int x;
                cin >> x;
                ++cnt[x];
        }

        vector < int > pref(n + 1);
        for (int i = 0 ; i <= n ; ++i) {
                if (i == 0) {
                        pref[i] = cnt[i];
                }else {
                        pref[i] = pref[i - 1] + cnt[i];
                }
        }

        i64 ans = 0;
        for (int i = 0 ; i <= n ; ++i) {
                ans += 1LL * cnt[i] * (cnt[i] - 1) * (cnt[i] - 2) / 6;
                if (i > 0) {
                        ans += 1LL * pref[i - 1] * (1LL * cnt[i] * (cnt[i] - 1) / 2);
                }
        }

        cout << ans;
}

int32_t main(){
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        
        int tc;
        cin >> tc;
        
        while (tc--){
                solveTC();
                cout << '\n';
        }
        
        return 0;
}
