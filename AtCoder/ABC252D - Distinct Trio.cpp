#include <bits/stdc++.h>

using namespace std;
using i64 = long long;
using ld = long double;

#define F first
#define S second

const int N = (int) 2e5 + 5;

int n , a[N];
i64 dp[N][4];

i64 solve(int i , int cnt){
        if(i >= n){
                return cnt == 3;
        }

        auto &ret = dp[i][cnt];
        if(ret != -1){
                return ret;
        }

        ret = solve(i + 1 , cnt);
        if(cnt < 3){
                int nxt = upper_bound(a , a + n , a[i]) - a;
                ret += solve(nxt , cnt + 1);
        }

        return ret;
}

int32_t main(){
        ios::sync_with_stdio(false);
        cin.tie(nullptr);

        cin >> n;

        for(int i = 0 ; i < n ; ++i) cin >> a[i];

        sort(a , a + n);

        memset(dp , -1 , sizeof dp);
        cout << solve(0 , 0);

        return 0;
}
