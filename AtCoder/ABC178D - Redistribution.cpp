#include <bits/stdc++.h>

using namespace std;
using i64 = long long;
using ld = long double;

#define F first
#define S second

const int MOD = (int) 1e9 + 7;

int32_t main(){
        ios::sync_with_stdio(false);
        cin.tie(nullptr);

        int S;
        cin >> S;

        vector < i64 > dp(S + 1 , 0LL);
        dp[0] = 1;
        for(int i = 0 ; i < S ; ++i){
                for(int j = 3 ; j <= S && i + j <= S ; ++j){
                        dp[i + j] += dp[i];
                        dp[i + j] %= MOD;
                }
        }

        cout << dp[S];

        return 0;
}
