#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

const int N = (int) 1e6 + 10;

int cnt[N];

int32_t main() {
        ios::sync_with_stdio(false);cin.tie(nullptr);
        cout.tie(nullptr);cout.precision(20);
        int n;
        cin >> n;
        for (int i = 0; i < n; ++i) {
                int x;
                cin >> x;
                cnt[x]++;
        }
        vector < int > v;
        for (int i = (int) 1e6; i >= 1; --i) {
                if((cnt[i] & 1) && cnt[i - 1])
                        cnt[i - 1]++;
                for (int j = 0; j < cnt[i] / 2; ++j)
                        v.push_back(i);
        }
        if((int) v.size() % 2)
                v.pop_back();
        i64 ans = 0;
        for (int i = 0; i + 1 < (int) v.size(); i += 2)
                ans += 1LL * v[i] * v[i + 1];
        cout << ans;
        return 0;
}
