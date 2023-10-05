#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

int32_t main(){
        ios::sync_with_stdio(false);
        cin.tie(nullptr);

        int n , x;
        cin >> n >> x;

        vector < int > h(n) , s(n);
        for(int i = 0 ; i < n ; ++i) cin >> h[i];
        for(int i = 0 ; i < n ; ++i) cin >> s[i];

        vector < int > dp(x + 1 , -1);
        dp[0] = 0;
        for(int i = 0 ; i < n ; ++i){
                for(int j = x ; j >= 0 ; --j){
                        if(dp[j] == -1) continue;
                        if(j + h[i] <= x){
                                dp[j + h[i]] = max(dp[j + h[i]] , dp[j] + s[i]);
                        }
                }
        }

        cout << *max_element(dp.begin() , dp.end());

        return 0;
}
