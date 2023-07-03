#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

int n;
i64 S;
vector < int > a;
i64 ans;

bool good(int k){
        vector < i64 > a2;
        for (int i = 1; i <= n; ++i) {
                a2.push_back(a[i - 1] + (1LL * i * k));
        }
        sort(a2.begin(), a2.end());
        i64 ret = 0;
        for (int i = 0; i < k; ++i) {
                ret += a2[i];
        }
        ans = ret;
        return ret <= S;
}

int32_t main() {
        ios::sync_with_stdio(false);cin.tie(nullptr);
        cout.tie(nullptr);cout.precision(20);
        cin >> n >> S;
        for (int i = 0; i < n; ++i) {
                int x;
                cin >> x;
                a.push_back(x);
        }
        int lo = 0 , hi = n + 1;
        while (hi - lo > 1){
                int mid = (lo + hi) / 2;
                if(good(mid))
                        lo = mid;
                else
                        hi = mid;
        }
        if(lo == 0){
                cout << "0 0";
                return 0;
        }
        good(lo);
        cout << lo << ' ' << ans;
        return 0;
}
