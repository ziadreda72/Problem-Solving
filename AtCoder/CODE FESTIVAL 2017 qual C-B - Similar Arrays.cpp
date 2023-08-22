#include <bits/stdc++.h>

using namespace std;
using i64 = long long;
using i128 = __int128;
using ld = long double;

#define F first
#define S second

int n;
int a[11] , dp[11][2];

int solve(int i , int x){
        if(i >= n)
                return !x;
        auto &ret = dp[i][x];
        if(~ret)
                return ret;
        ret = 0;
        for(int j = -1 ; j <= 1 ; ++j)
                ret += solve(i + 1 , ((x % 2) * ((a[i] + j) % 2)) % 2);
        return ret;
}

int32_t main(){
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        cin >> n;
        for(int i = 0 ; i < n ; ++i)
                cin >> a[i];
        memset(dp , -1 , sizeof dp);
        int ans = 0;
        for(int i = -1 ; i <= 1 ; ++i)
                ans += solve(1 , (a[0] + i) % 2);
        cout << ans;
        return 0;
}
