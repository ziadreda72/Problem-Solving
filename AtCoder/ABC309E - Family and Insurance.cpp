#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

int32_t main(){
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        int n , m;
        cin >> n >> m;
        vector < int > p(n + 1);
        for (int i = 2; i <= n; ++i)
                cin >> p[i];
        vector < int > dp(n + 1 , -1);
        while (m--){
                int x , y;
                cin >> x >> y;
                dp[x] = max(dp[x] , y);
        }
        for (int i = 2; i <= n; ++i)
                dp[i] = max(dp[i] , dp[p[i]] - 1);
        int ans = 0;
        for (int i = 1; i <= n; ++i)
                ans += dp[i] >= 0;
        cout << ans;
        return 0;
}
