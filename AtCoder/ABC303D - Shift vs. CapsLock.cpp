#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

int32_t main(){
        ios::sync_with_stdio(false);
        cin.tie(nullptr);

        int x , y , z;
        cin >> x >> y >> z;

        string s;
        cin >> s;

        vector < i64 > dp(2);
        dp[0] = 0 , dp[1] = z;
        for(auto c : s){
                dp[0] = min(dp[0] , dp[1] + z);
                dp[1] = min(dp[1] , dp[0] + z);
                if(c == 'a'){
                        dp[0] += x;
                        dp[1] += y;
                }else{
                        dp[0] += y;
                        dp[1] += x;
                }
        }

        cout << min(dp[0] , dp[1]);

        return 0;
}
