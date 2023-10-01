#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

int32_t main(){
        ios::sync_with_stdio(false);
        cin.tie(nullptr);

        int N , K , D;
        cin >> N >> K >> D;

        vector < int > a(N);
        for(int i = 0 ; i < N ; ++i) cin >> a[i];

        vector dp(N + 1 , vector (K + 1 , vector < i64 > (D , -1)));
        dp[0][0][0] = 0;
        for(int i = 0 ; i < N ; ++i){
                for(int j = 0 ; j <= K ; ++j){
                        for(int k = 0 ; k < D ; ++k){
                                if(dp[i][j][k] == -1) continue;

                                dp[i + 1][j][k] = max(dp[i + 1][j][k] , dp[i][j][k]);

                                if(j != K){
                                        dp[i + 1][j + 1][(k + a[i]) % D] = max(dp[i + 1][j + 1][(k + a[i]) % D] , dp[i][j][k] + a[i]);
                                }
                        }
                }
        }

        cout << dp[N][K][0];

        return 0;
}
