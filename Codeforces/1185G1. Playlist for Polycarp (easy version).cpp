#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

const int MOD = (int) 1e9 + 7;

int add(int a , int b){
        a %= MOD;
        b %= MOD;
        return (a + b) % MOD;
}

int32_t main(){
        ios::sync_with_stdio(false);
        cin.tie(nullptr);

        int N , T;
        cin >> N >> T;

        vector < int > a(N) , g(N);
        for(int i = 0 ; i < N ; ++i){
                cin >> a[i] >> g[i];
                --g[i];
        }

        vector dp(1 << N , vector < int > (3 , 0));
        for(int i = 0 ; i < N ; ++i){
                dp[1 << i][g[i]] = 1;
        }

        for(int msk = 0 ; msk < (1 << N) ; ++msk){
                for(int lst = 0 ; lst < 3 ; ++lst){
                        if(dp[msk][lst] == 0) continue;
                        for(int i = 0 ; i < N ; ++i){
                                if(((msk >> i) & 1) || lst == g[i]) continue;
                                int new_msk = msk | (1 << i);
                                dp[new_msk][g[i]] = add(dp[new_msk][g[i]] , dp[msk][lst]);
                        }
                }
        }

        int ans = 0;
        for(int msk = 0 ; msk < (1 << N) ; ++msk){
                int sum = 0;
                for(int i = 0 ; i < N ; ++i){
                        sum += ((msk >> i) & 1) * a[i];
                }
                if(sum != T) continue;

                for(int i = 0 ; i < 3 ; ++i){
                        ans = add(ans , dp[msk][i]);
                }
        }

        cout << ans;

        return 0;
}
