#include <bits/stdc++.h>

using namespace std;

const int MOD = (int) 1e9 + 7 , N = 105;

int add(int a , int b) {
    return ( 1LL * (a % MOD ) + (b % MOD ) ) % MOD;
}

int n , k , d;
int dp[N][2];

int solve(int s , int ok){
    if(s > n)
        return 0;
    if(s == n)
        return ok ? 1 : 0;
    auto &ret = dp[s][ok];
    if(~ret)
        return ret;
    ret = 0;
    for (int i = 1; i <= k; ++i) {
        ret = add(ret , solve(s + i , ok | (i >= d ? 1 : 0)));
    }
    return ret;
}

int32_t main() {
    ios::sync_with_stdio(false);cin.tie(nullptr);
    cout.tie(nullptr);cout.precision(20);
    cin >> n >> k >> d;
    memset(dp , -1 , sizeof dp);
    cout << solve(0 , 0);
    return 0;
}
