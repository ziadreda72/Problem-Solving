#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

const int MOD = (int) 1e9 + 7;

int32_t main(){
        ios::sync_with_stdio(false);
        cin.tie(nullptr);

        int n;
        cin >> n;

        vector < string > g(n);
        for(int i = 0 ; i < n ; ++i) cin >> g[i];

        auto check = [&](int i , int j){
                return (0 <= i && i < n) && (0 <= j && j < n) && g[i][j] != '*';
        };

        vector < vector < i64 > > dp(n , vector < i64 > (n , 0LL));
        dp[0][0] = g[0][0] == '.';
        for(int i = 0 ; i < n ; ++i){
                for(int j = 0 ; j < n ; ++j){
                        if(check(i , j + 1)){
                                dp[i][j + 1] += dp[i][j];
                                dp[i][j + 1] %= MOD;
                        }
                        if(check(i + 1 , j)){
                                dp[i + 1][j] += dp[i][j];
                                dp[i + 1][j] %= MOD;
                        }
                }
        }

        cout << dp[n - 1][n - 1];

        return 0;
}
