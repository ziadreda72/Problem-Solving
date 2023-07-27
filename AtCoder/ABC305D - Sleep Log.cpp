#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

const int N = (int) 2e5 + 5;

int n;
i64 a[N] , pref[N];

int L(i64 x){
        int lo = 0 , hi = n + 1;
        while (hi - lo > 1){
                int mid = (lo + hi) / 2;
                if(a[mid] <= x)
                        lo = mid;
                else
                        hi = mid;
        }
        return lo;
}

int R(i64 x){
        int lo = 0 , hi = n + 1;
        while (hi - lo > 1){
                int mid = (lo + hi) / 2;
                if(a[mid] >= x)
                        hi = mid;
                else
                        lo = mid;
        }
        return hi;
}

int32_t main() {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        cin >> n;
        i64 prev = 0;
        for (int i = 1; i <= n; ++i) {
                cin >> a[i];
                if(i >= 3 && i % 2 == 1){
                        pref[i] = prev + (a[i] - a[i - 1]);
                        prev = pref[i];
                }else{
                        pref[i] = prev;
                }
        }
        int q;
        cin >> q;
        while (q--){
                i64 l , r;
                cin >> l >> r;
                i64 ans = 0;
                int r2 = R(l);
                if(r2 % 2 == 1)
                        ans += a[r2] - l;
                ans -= pref[r2];
                int l2 = L(r);
                if(l2 % 2 == 0)
                        ans += r - a[l2];
                ans += pref[l2];
                cout << ans << '\n';
        }
        return 0;
}
