#include <bits/stdc++.h>

using namespace std;
using i64 = long long;
using ld = long double;

#define F first
#define S second

const i64 INF = (i64) 1e15;

int32_t main(){
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        int n;
        cin >> n;
        vector < int > a(n);
        for(int i = 0 ; i < n ; ++i){
                cin >> a[i];
        }
        vector < vector < i64 > > dp(n + 1 , vector < i64 > (2 , -INF));
        dp[0][0] = 0;
        for(int i = 0 ; i < n ; ++i){
                dp[i + 1][0] = max(dp[i][0] + a[i] , dp[i][1] - a[i]);
                dp[i + 1][1] = max(dp[i][0] - a[i] , dp[i][1] + a[i]);
        }
        cout << dp[n][0];
        return 0;
}
