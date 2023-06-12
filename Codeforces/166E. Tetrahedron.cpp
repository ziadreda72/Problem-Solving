#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

const int N = (int) 1e7 + 100 , MOD = (int) 1e9 + 7;

int add(int a , int b){
        return 1LL * (a + b) % MOD;
}

int dp[N][4];

int32_t main() {
        ios::sync_with_stdio(false);cin.tie(nullptr);
        cout.tie(nullptr);cout.precision(20);
        int n;
        cin >> n;
        dp[0][0] = 1;
        for (int i = 0; i < n; ++i) {
                for (int j = 0; j < 4; ++j) {
                        for (int k = 0; k < 4; ++k) {
                                if(j == k)
                                        continue;
                                dp[i + 1][j] = add(dp[i + 1][j] , dp[i][k]);
                        }
                }
        }
        cout << dp[n][0];
        return 0;
}
