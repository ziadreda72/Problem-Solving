#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

#define F first
#define S second

const int N = 105 , M = 1105;

int st , en , T , d;
int dp[N][M];

int solve(int t , int s){
    if(t >= T){
        return s == en ? s : -1e8;
    }
    int &ret = dp[t][s];
    if(~ret) return ret;
    int ans = solve(t + 1 , s) + s;
    for (int i = 1; i <= d; ++i) {
        ans = max(ans , solve(t + 1 , s + i) + s);
        if(s - i >= 0){
            ans = max(ans , solve(t + 1 , s - i) + s);
        }
    }
    return ret = ans;
}

int32_t main() {
    ios::sync_with_stdio(false);cin.tie(nullptr);
    cout.tie(nullptr);cout.precision(20);
    cin >> st >> en >> T >> d;
    memset(dp , -1 , sizeof dp);
    cout << solve(1 , st);
    return 0;
}
