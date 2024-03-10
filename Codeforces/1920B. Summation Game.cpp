#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

void solveTC(){
        int n , k , x;
        cin >> n >> k >> x;

        vector < i64 > a(n) , pref(n);
        for (int i = 0 ; i < n ; ++i) cin >> a[i];

        sort(a.begin() , a.end());

        for (int i = 0 ; i < n ; ++i) {
                if (i == 0) pref[i] = a[i];
                else pref[i] = pref[i - 1] + a[i];
        }

        int ans = INT32_MIN;
        for (int i = 0 ; i <= k ; ++i) {
                int r = n - 1 - i;
                int l = n - i - x;
                if (r < 0) {
                        ans = max(ans , 0);
                        continue;
                }
                int pos = (l > 0 ? pref[l - 1] : 0);
                int neg = pref[r] - (l > 0 ? pref[l - 1] : 0);
                ans = max(ans , pos - neg);
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
