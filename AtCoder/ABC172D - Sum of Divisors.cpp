#include <bits/stdc++.h>

using namespace std;
using i64 = long long;
using ld = long double;

#define F first
#define S second

int32_t main(){
        ios::sync_with_stdio(false);
        cin.tie(nullptr);

        int n;
        cin >> n;

        vector < i64 > dp(n + 1);
        iota(dp.begin() , dp.end() , 0);
        for(int i = 2 ; i <= n ; ++i){
                for(int j = i ; j <= n ; j += i){
                        dp[j] += j;
                }
        }

        cout << accumulate(dp.begin() , dp.end() , 0LL);

        return 0;
}
