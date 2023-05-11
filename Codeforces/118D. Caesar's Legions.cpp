#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

#define F first
#define S second

const int N = 105 , M = 15 , MOD = (int) 1e8;

int add(int a , int b){
    return (1LL * (a % MOD + b % MOD)) % MOD;
}

int n1 , n2 , k1 , k2;
int dp[N][N][M][M];

int solve(int x , int y , int cnt , int cnt2){
    if(x == 0 && y == 0)
        return cnt <= k1 && cnt2 <= k2;
    auto &ret = dp[x][y][cnt][cnt2];
    if(~ret)
        return ret;
    ret = 0;
    if(x && cnt + 1 <= k1)
        ret = add(ret , solve(x - 1 , y , cnt + 1 , 0));
    if(y && cnt2 + 1 <= k2)
        ret = add(ret , solve(x , y - 1 , 0 , cnt2 + 1));
    return ret % MOD;
}

int32_t main() {
    ios::sync_with_stdio(false);cin.tie(nullptr);
    cout.tie(nullptr);cout.precision(20);
    cin >> n1 >> n2 >> k1 >> k2;
    memset(dp , -1 , sizeof dp);
    int sol = solve(n1 , n2 , 0 , 0) % MOD;
    cout << sol;
    return 0;
}
