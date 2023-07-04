#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

int32_t main() {
        ios::sync_with_stdio(false);cin.tie(nullptr);
        cout.tie(nullptr);cout.precision(20);
        int k;
        string s;
        cin >> k >> s;
        int n = (int) s.size();
        s = '?' + s;
        vector < int > pref(n + 1 , 0);
        for (int i = 1; i <= n; ++i) {
                pref[i] = s[i] == '1';
                pref[i] += pref[i - 1];
        }
        i64 ans = 0;
        for (int i = 1; i <= n; ++i) {
                int L = lower_bound(pref.begin() + i , pref.end() , k + pref[i - 1]) - pref.begin();
                int R = upper_bound(pref.begin() + i , pref.end() , k + pref[i - 1]) - pref.begin();
                ans += 1LL * (R - L);
        }
        cout << ans;
        return 0;
}
