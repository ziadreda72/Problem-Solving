#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

const int N = 2005 , MOD = (int) 1e9 + 7;

int add(int a , int b) {
        return ( 1LL * (a % MOD ) + (b % MOD ) ) % MOD;
}

int n , k;
int dp[N][N];

int solve(int i , int lst){
        if(i == k)
                return 1;
        auto &ret = dp[i][lst];
        if(~ret)
                return ret;
        ret = 0;
        for (int j = lst; j <= n; j += lst) {
                ret = add(ret , solve(i + 1 , j));
        }
        return ret;
}

int32_t main() {
        ios::sync_with_stdio(false);cin.tie(nullptr);
        cout.tie(nullptr);cout.precision(20);
        cin >> n >> k;
        memset(dp , -1 , sizeof dp);
        cout << solve(0 , 1);
        return 0;
}
