#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

int n , P;

int mul(int a , int b){
        return (1LL * (a % P) * (b % P) % P);
}

int32_t main() {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        cin >> n >> P;
        vector < int > a(n);
        for (int i = 0; i < n; ++i) {
                cin >> a[i];
        }
        if(n <= P){
                int ans = 1;
                for (int i = 0; i < n; ++i) {
                        for (int j = i + 1; j < n; ++j) {
                                ans = mul(ans , abs(a[i] - a[j]));
                        }
                }
                cout << ans;
                return 0;
        }
        cout << 0;
        return 0;
}
