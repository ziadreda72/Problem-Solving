#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

int32_t main(){
        ios::sync_with_stdio(false);
        cin.tie(nullptr);

        const int MOD = 998244353;

        auto add = [&](i64 a , i64 b){
                a %= MOD;
                b %= MOD;
                return 1LL * (a + b) % MOD;
        };

        auto mul = [&](i64 a , i64 b){
                a %= MOD;
                b %= MOD;
                return 1LL * (a * b) % MOD;
        };

        vector < i64 > pw(19);

        pw[0] = 1LL;
        for(int i = 1 ; i <= 18 ; ++i){
                pw[i] = pw[i - 1] * 10;
        }

        i64 N;
        cin >> N;

        i64 ans = 0;
        for(int i = 0 ; i <= 17 && pw[i] <= N ; ++i){

                i64 X = min(pw[i + 1] - 1 , N) - pw[i] + 1;
                i64 Y = X + 1;

                if(X % 2 == 0) X /= 2;
                if(Y % 2 == 0) Y /= 2;

                ans = add(ans , mul(X , Y));
        }

        cout << ans;

        return 0;
}
