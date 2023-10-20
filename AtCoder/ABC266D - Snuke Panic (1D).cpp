#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

int32_t main(){
        ios::sync_with_stdio(false);
        cin.tie(nullptr);

        int N;
        cin >> N;

        map < int , array < int , 2 > > mp;
        int T = -1;
  
        while(N--){
                int t , x , a;
                cin >> t >> x >> a;
                mp[t] = {x , a};
                T = max(T , t);
        }

        vector dp(T + 1 , vector < i64 > (5 , -1));

        dp[0][0] = 0;
        for(int t = 1 ; t <= T ; ++t){
                for(int x = 0 ; x < 5 ; ++x){
                        auto A = mp.count(t) && mp[t][0] == x ? mp[t][1] : 0;
                        if(dp[t - 1][x] != -1){
                                dp[t][x] = max(dp[t][x] , dp[t - 1][x] + A);
                        }
                        if(x - 1 >= 0 && dp[t - 1][x - 1] != -1){
                                dp[t][x] = max(dp[t][x] , dp[t - 1][x - 1] + A);
                        }
                        if(x + 1 <= 4 && dp[t - 1][x + 1] != -1){
                                dp[t][x] = max(dp[t][x] , dp[t - 1][x + 1] + A);
                        }
                }
        }

        i64 ans = 0;
        for(int i = 0 ; i < 5 ; ++i) ans = max(ans , dp[T][i]);

        cout << ans;

        return 0;
}
