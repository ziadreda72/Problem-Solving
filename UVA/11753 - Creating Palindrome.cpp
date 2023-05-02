#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

#define F first
#define S second

const int N = (int) 1e4 + 10 , M = 25;

int n , k;
int a[N] , dp[N][M][M];
int id;

int solve(int i , int k1 , int k2){
    int j = n - i - 1 - k1 + k2;
    if(i >= j) return 0;
    auto &ret = dp[i][k1][k2];
    if(ret != -1) return ret;
    if(k1 + k2 > k) return 100;
    if(a[i] == a[j]) return ret = solve(i + 1 , k1 , k2);
    return ret = min(solve(i , k1 + 1 , k2) + 1 , solve(i + 1 , k1 , k2 + 1) + 1);
}

void solveTC() {
    cin >> n >> k;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    id++;
    memset(dp , -1 , sizeof dp);
    int sol = solve(0 , 0 , 0);
    if(sol == 0){
        printf("Case %d: Too easy\n",id);
    }else if(sol > k){
        printf("Case %d: Too difficult\n",id);
    }else{
        printf("Case %d: %d\n",id,sol);
    }
}

int32_t main() {
    ios::sync_with_stdio(false);cin.tie(nullptr);
    cout.tie(nullptr);cout.precision(20);
    int tc = 1;
    cin >> tc;
    while(tc--){
        solveTC();
    }
    return 0;
}
