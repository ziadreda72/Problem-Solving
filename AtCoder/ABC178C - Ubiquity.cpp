#include <bits/stdc++.h>

using namespace std;
using i64 = long long;
using ld = long double;

#define F first
#define S second

const int MX = (int) 1e6 + 5 , MOD = (int) 1e9 + 7;

int n , dp[MX][2][2];

int add(int a , int b){
        a %= MOD;
        b %= MOD;
        return 1LL * (a + b) % MOD;
}

int solve(int i , bool f , bool f2){
        if(i >= n){
                return f && f2;
        }

        auto &ret = dp[i][f][f2];
        if(ret != -1){
                return ret;
        }

        ret = 0;
        for(int j = 0 ; j < 10 ; ++j){
                ret = add(ret , solve(i + 1 , f || (j == 0) , f2 || (j == 9)));
        }

        return ret;
}

int32_t main(){
        ios::sync_with_stdio(false);
        cin.tie(nullptr);

        cin >> n;

        memset(dp , -1 , sizeof dp);
        cout << solve(0 , 0 , 0);

        return 0;
}
