#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

int32_t main(){
        ios::sync_with_stdio(false);
        cin.tie(nullptr);

        string s , t;
        cin >> s >> t;

        int M = (int) t.size();

        auto build_dp = [&](vector < bool > &dp){
                dp[0] = 1;
                for(int i = 1 ; i <= M ; ++i){
                        dp[i] = dp[i - 1] && ((s[i - 1] == '?' || t[i - 1] == '?') || (s[i - 1] == t[i - 1]));
                }
        };

        vector < bool > dp(M + 1);
        build_dp(dp);

        reverse(s.begin() , s.end());
        reverse(t.begin() , t.end());

        vector < bool > dp2(M + 1);
        build_dp(dp2);

        for(int i = 0 ; i <= M ; ++i){
                cout << (dp[i] && dp2[M - i] ? "Yes" : "No") << '\n';
        }

        return 0;
}
