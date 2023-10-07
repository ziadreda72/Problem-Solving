#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

const int MOD = (int) 1e9 + 7;

int32_t main(){
        ios::sync_with_stdio(false);
        cin.tie(nullptr);

        int n , x;
        cin >> n >> x;

        vector < int > a(n);
        for(int i = 0 ; i < n ; ++i) cin >> a[i];

        vector < i64 > dp(x + 1 , 0LL);
        dp[0] = 1;
        for(auto c : a){
                for(int i = 0 ; i + c <= x ; ++i){
                        dp[i + c] += dp[i];
                        dp[i + c] %= MOD;
                }
        }

        cout << dp[x];

        return 0;
}
