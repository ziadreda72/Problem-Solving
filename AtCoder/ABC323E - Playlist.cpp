#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

const int MOD = 998244353;

i64 add(i64 a , i64 b){
        return (1LL * ((a % MOD) + (b % MOD))) % MOD;
}

i64 mul(i64 a , i64 b){
        return (1LL * ((a % MOD) * (b % MOD))) % MOD;
}

i64 POW(i64 a , i64 b){
        i64 ret = 1;
        while(b){
                if(b & 1)
                        ret = (ret * a) % MOD;
                a = (a * a) % MOD;
                b >>= 1;
        }
        return ret;
}

i64 mod_inv(i64 a){
        return POW(a , MOD - 2);
}

int32_t main(){
        ios::sync_with_stdio(false);
        cin.tie(nullptr);

        int N , X;
        cin >> N >> X;

        vector < int > a(N);
        for(int i = 0 ; i < N ; ++i) cin >> a[i];

        vector < i64 > dp(X + 1);
        dp[0] = 1LL;
        for(int i = 1 ; i <= X ; ++i) {
                for(int j = 0 ; j < N ; ++j) {
                        if(i - a[j] < 0) continue;
                        dp[i] = add(dp[i] , dp[i - a[j]]);
                }
                dp[i] = mul(dp[i] , mod_inv(N));
        }

        i64 ans = 0;
        for(int i = max(0 , X - a[0] + 1) ; i <= X ; ++i) {
                ans = add(ans , dp[i]);
        }
        ans = mul(ans , mod_inv(N));

        cout << ans;

        return 0;
}
