#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

void solveTC(){
        int n , m , x;
        cin >> n >> m >> x;
        --x;

        vector < bool > dp(n , 0);
        dp[x] = 1;

        while (m--) {
                int r;
                char c;
                cin >> r >> c;
                vector < bool > new_dp(n , 0);
                for (int i = 0 ; i < n ; ++i) {
                        if (dp[i]) {
                                if (c == '0')
                                        new_dp[(i + r + n) % n] = 1;
                                else if (c == '1')
                                        new_dp[(i - r + n) % n] = 1;
                                else {
                                        new_dp[(i + r + n) % n] = 1;
                                        new_dp[(i - r + n) % n] = 1;
                                }
                        }
                }
                dp = new_dp;
        }

        vector < int > ans;
        for (int i = 0 ; i < n ; ++i)
                if (dp[i]) ans.push_back(i + 1);

        cout << ans.size() << '\n';
        for (auto x : ans) cout << x << ' ';
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
