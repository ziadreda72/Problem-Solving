#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

int32_t main() {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        int n , m , k;
        cin >> n >> m >> k;
        vector < int > a(n) , pos(n + 1);
        for (int i = 0; i < n; ++i) {
                int x;
                cin >> x;
                a[i] = x;
                pos[x] = i;
        }
        i64 ans = 0;
        while (m--){
                int x;
                cin >> x;
                ans += (pos[x] / k) + 1;
                int i = pos[x];
                if(i == 0)
                        continue;
                int y = a[i - 1];
                swap(a[i] , a[i - 1]);
                swap(pos[x] , pos[y]);
        }
        cout << ans;
        return 0;
}
