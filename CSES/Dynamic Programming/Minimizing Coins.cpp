#include <bits/stdc++.h>
 
using namespace std;
using i64 = long long;
 
const int inf = (int) 1e9;
 
int32_t main(){
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
 
        int n , x;
        cin >> n >> x;
 
        vector < int > dp(x + 1 , inf);
        dp[0] = 0;
        for(int i = 0 ; i < n ; ++i){
                int c;
                cin >> c;
                for(int j = 0 ; j + c <= x ; ++j){
                        dp[j + c] = min(dp[j + c] , dp[j] + 1);
                }
        }
 
        cout << (dp[x] == inf ? -1 : dp[x]);
 
        return 0;
}
