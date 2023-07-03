#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

int32_t main() {
        ios::sync_with_stdio(false);cin.tie(nullptr);
        cout.tie(nullptr);cout.precision(20);
        int n;
        cin >> n;
        vector < pair < int , int > > a(n);
        for (int i = 0; i < n; ++i) {
                cin >> a[i].first;
                a[i].second = i + 1;
        }
        sort(a.begin(), a.end());
        vector < int > ans[2];
        for (int i = 0; i < n; ++i) {
                ans[i & 1].push_back(a[i].second);
        }
        for (int i = 0; i < 2; ++i) {
                cout << ans[i].size() << '\n';
                for(auto x : ans[i])
                        cout << x << ' ';
                cout << '\n';
        }
        return 0;
}
