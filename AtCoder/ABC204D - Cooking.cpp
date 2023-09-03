#include <bits/stdc++.h>

using namespace std;
using i64 = long long;
using ld = long double;

#define F first
#define S second

int32_t main(){
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        int n;
        cin >> n;
        vector < int > a(n);
        int S = 0;
        for(int i = 0 ; i < n ; ++i){
                cin >> a[i];
                S += a[i];
        }
        vector < vector < bool > > dp(n + 1 , vector < bool > (S + 1 , false));
        dp[0][0] = 1;
        for(int i = 0 ; i < n ; ++i){
                for(int j = 0 ; j <= S ; ++j){
                        if(dp[i][j]){
                                dp[i + 1][j] = 1;
                                dp[i + 1][j + a[i]] = 1;
                        }
                }
        }
        int ans = S;
        for(int i = 0 ; i <= S ; ++i){
                if(dp[n][i]){
                        ans = min(ans , max(i , S - i));
                }
        }
        cout << ans;
        return 0;
}
