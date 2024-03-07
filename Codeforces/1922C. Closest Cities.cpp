#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

void solveTC(){
        int n;
        cin >> n;

        vector < i64 > a(n);
        for (int i = 0 ; i < n ; ++i) cin >> a[i];

        vector < i64 > pref(n);
        pref[1] = 1;
        for (int i = 1 ; i + 1 < n ; ++i) {
                pref[i + 1] = (a[i + 1] - a[i] < a[i] - a[i - 1] ? 1 : a[i + 1] - a[i]);
        }

        vector < i64 > suf(n);
        suf[n - 2] = 1;
        for (int i = n - 2 ; i >= 1 ; --i) {
                suf[i - 1] = (a[i] - a[i - 1] < a[i + 1] - a[i] ? 1 : a[i] - a[i - 1]);
        }

        for (int i = 1 ; i < n ; ++i) pref[i] += pref[i - 1];
        for (int i = n - 2 ; i >= 0 ; --i) suf[i] += suf[i + 1];

        int q;
        cin >> q;

        while (q--) {
                int x , y;
                cin >> x >> y;
                --x , --y;
                if (x < y) {
                        cout << pref[y] - pref[x] << '\n';
                }else {
                        cout << suf[y] - suf[x] << '\n';
                }
        }
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
