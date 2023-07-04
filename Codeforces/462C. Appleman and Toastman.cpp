#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

int32_t main() {
        ios::sync_with_stdio(false);cin.tie(nullptr);
        cout.tie(nullptr);cout.precision(20);
        int n;
        cin >> n;
        vector < int > a(n);
        i64 sum = 0;
        i64 ans = 0;
        for (int i = 0; i < n; ++i) {
                cin >> a[i];
                sum += a[i];
        }
        ans = sum;
        sort(a.rbegin(), a.rend());
        while (a.size() > 1){
                ans += sum;
                sum -= a.back();
                a.pop_back();
        }
        cout << ans;
        return 0;
}
