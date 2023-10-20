#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

int32_t main(){
        ios::sync_with_stdio(false);
        cin.tie(nullptr);

        int N , M;
        cin >> N >> M;

        vector < string > S(N);
        for(int i = 0 ; i < N ; ++i) cin >> S[i];

        vector dp(N , vector < bool > (M , 0));

        auto check = [&](int i , int j){
                return (0 <= i && i < N) && (0 <= j && j < M) && S[i][j] != '#';
        };

        dp[0][0] = 1;

        for(int i = 0 ; i < N ; ++i){
                for(int j = 0 ; j < M ; ++j){
                        if(dp[i][j]){
                                if(check(i + 1 , j)){
                                        dp[i + 1][j] = 1;
                                }
                                if(check(i , j + 1)){
                                        dp[i][j + 1] = 1;
                                }
                        }
                }
        }

        int ans = 0;
        for(int i = 0 ; i < N ; ++i){
                for(int j = 0 ; j < M ; ++j){
                        ans = max(ans , (i + j + 1) * dp[i][j]);
                }
        }

        cout << ans;

        return 0;
}
