#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

const int inf = INT32_MAX;

int32_t main() {
        ios::sync_with_stdio(false);cin.tie(nullptr);
        cout.tie(nullptr);cout.precision(20);
        int n , c;
        cin >> n >> c;
        vector < int > a(n - 1) , b(n - 1);
        for (int i = 0; i + 1 < n; ++i)
                cin >> a[i];
        for(int i = 0; i + 1 < n; ++i)
                cin >> b[i];
        vector < vector < int > > dp(n , vector < int >(2 , inf));
        dp[0][0] = 0;
        for (int i = 0; i + 1 < n; ++i) {
                if(dp[i][0] != inf){
                        dp[i + 1][0] = min(dp[i + 1][0] , dp[i][0] + a[i]);
                        dp[i + 1][1] = min(dp[i + 1][1] , dp[i][0] + b[i] + c);
                }
                if(dp[i][1] != inf){
                        dp[i + 1][1] = min(dp[i + 1][1] , dp[i][1] + b[i]);
                        dp[i + 1][0] = min(dp[i + 1][0] , dp[i][1] + a[i]);
                }
        }
        for (int i = 0; i < n; ++i)
                cout << min(dp[i][0] , dp[i][1]) << ' ';
        return 0;
}
