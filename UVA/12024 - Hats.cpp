#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

i64 fact[15];

void solveTC(){
        int n;
        cin >> n;

        vector < i64 > dp(1 << n);
  
        dp[0] = 1;
        for(int msk = 0 ; msk < (1 << n) ; ++msk){
                int i = __builtin_popcount(msk);
                for(int j = 0 ; j < n ; ++j){
                        if(((msk >> j) & 1) || i == j) continue;
                        dp[msk | (1 << j)] += dp[msk];
                }
        }

        cout << dp.back() << '/' << fact[n];
}

int32_t main(){
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        
        fact[0] = 1;
        for(i64 i = 1 ; i < 15 ; ++i) fact[i] = fact[i - 1] * i;

        int tc;
        cin >> tc;
        
        while (tc--){
                solveTC();
                cout << '\n';
        }
        
        return 0;
}
