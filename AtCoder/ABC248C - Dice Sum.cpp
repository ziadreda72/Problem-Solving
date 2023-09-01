#include <bits/stdc++.h>

using namespace std;
using i64 = long long;
using ld = long double;

#define F first
#define S second

const int N = 55 , MOD = 998244353;

int n , m , k;
int dp[N][N * N];

int solve(int i , int sum){
        if(i >= n){
                return sum <= k;
        }
        auto &ret = dp[i][sum];
        if(ret != -1){
                return ret;
        }        
        ret = 0;
        for(int j = 1 ; j <= m ; ++j){
                ret = (1LL * (ret + solve(i + 1 , sum + j)) % MOD);
        }
        return ret % MOD;
}

int32_t main(){
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        cin >> n >> m >> k;
        memset(dp , -1 , sizeof dp);
        cout << solve(0 , 0);
        return 0;
}
