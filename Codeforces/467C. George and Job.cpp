#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

#define F first
#define S second

const int N = 5050;
const i64 OO = (i64) -1e18;

int n , m , k;
i64 a[N] , pref[N] , dp[N][N];

i64 solve(int i , int cnt){
    if(i > n){
        if(cnt != k) return OO;
        return 0;
    }
    i64 &ret = dp[i][cnt];
    if(ret != -1) return ret;
    ret = solve(i + 1 , cnt);
    if(i + m - 1 <= n){
        ret = max(ret , solve(i + m , cnt + 1) + pref[i + m - 1] - pref[i - 1]);
    }
    return ret;
}

int32_t main() {
    ios::sync_with_stdio(false);cin.tie(nullptr);
    cout.tie(nullptr);cout.precision(20);
    cin >> n >> m >> k;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    pref[0] = 0;
    for (int i = 1; i <= n; ++i) {
        pref[i] = pref[i - 1] + a[i];
    }
    memset(dp , -1 , sizeof dp);
    cout << solve(1 , 0);
    return 0;
}
