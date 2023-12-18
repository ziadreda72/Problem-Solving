#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

const int MOD = (int) 1e9 + 7 , MAX = (int) 1e5 + 5;

int n , m , a[MAX] , b[MAX];
i64 dp[MAX][2] , m2;

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

i64 solve(int i , int j) {
        if(i >= n) {
                return j;
        }

        auto &ret = dp[i][j];
        if(ret != -1) {
                return ret;
        }

        ret = 0;

        if(j == 1) {
                if(a[i] == 0 && b[i] == 0) {
                        ret = add(ret , mul(mul(m , m) , solve(i + 1 , 1)));
                }
                else if(a[i] == 0 || b[i] == 0) {
                        ret = add(ret , mul(m , solve(i + 1 , 1)));
                }
                else {
                        ret = add(ret , solve(i + 1 , 1));
                }
        }
        else {
                if(a[i] == 0 && b[i] == 0) {
                        ret = add(ret , add(mul(m , solve(i + 1 , 0)) , mul(m2 , solve(i + 1 , 1))));
                }
                else if(a[i] == 0) {
                        ret = add(ret , add(solve(i + 1 , 0) , mul((m - b[i]) , solve(i + 1 , 1))));
                }
                else if(b[i] == 0) {
                        ret = add(ret , add(solve(i + 1 , 0) , mul(a[i] - 1 , solve(i + 1 , 1))));
                }
                else if(a[i] >= b[i]) {
                        ret = add(ret , solve(i + 1 , a[i] > b[i] ? 1 : 0));
                }
        }

        return ret;
}

int32_t main(){
        ios::sync_with_stdio(false);
        cin.tie(nullptr);

        cin >> n >> m;

        m2 = 1LL * m * (m - 1) / 2;

        i64 cnt0 = 0;

        for(int i = 0 ; i < n ; ++i) cin >> a[i] , cnt0 += a[i] == 0;
        for(int j = 0 ; j < n ; ++j) cin >> b[j] , cnt0 += b[j] == 0;

        memset(dp , -1 , sizeof dp);

        auto P = solve(0 , 0);
        auto Q = mod_inv(POW(m , cnt0));

        cout << mul(P , Q);

        return 0;
}
