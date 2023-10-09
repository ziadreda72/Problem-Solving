#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

int32_t main(){
        ios::sync_with_stdio(false);
        cin.tie(nullptr);

        int N , X;
        cin >> N >> X;

        vector < int > a(N);
        for(int i = 0 ; i < N ; ++i) cin >> a[i];

        vector < array < int , 2 > > dp(1 << N , {25 , X});
        dp[0] = {1 , 0};
        for(int msk = 0 ; msk < (1 << N) ; ++msk){
                for(int i = 0 ; i < N ; ++i){
                        if((msk >> i) & 1) continue;
                        auto cur = dp[msk];
                        if(cur[1] + a[i] > X){
                                cur[0]++;
                                cur[1] = a[i];
                        }else{
                                cur[1] += a[i];
                        }
                        dp[msk | (1 << i)] = min(dp[msk | (1 << i)] , cur);
                }
        }

        cout << dp.back()[0];

        return 0;
}
