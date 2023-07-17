#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

int32_t main() {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        int n;
        cin >> n;
        int mx = 0 , g = 0;
        for (int i = 0; i < n; ++i) {
                int x;
                cin >> x;
                mx = max(mx , x);
                g = gcd(g , x);
        }
        cout << (((mx / g) - n) & 1 ? "Alice" : "Bob");
	return 0;
}
