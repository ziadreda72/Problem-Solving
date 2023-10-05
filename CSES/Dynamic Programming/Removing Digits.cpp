#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

const int inf = (int) 1e9;

int32_t main(){
        ios::sync_with_stdio(false);
        cin.tie(nullptr);

        int n;
        cin >> n;

        vector < int > dp(n + 1 , inf);
        dp[n] = 0;
        for(int i = n ; i > 0 ; --i){
                if(dp[i] == inf) continue;
                int x = i;
                while(x){
                        int j = x % 10;
                        dp[i - j] = min(dp[i - j] , dp[i] + 1);
                        x /= 10;
                }
        }

        cout << dp[0];

        return 0;
}
