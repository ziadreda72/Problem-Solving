#include <bits/stdc++.h>

using namespace std;
using i64 = long long;
using ld = long double;

#define F first
#define S second

const int N = 2005;
const i64 INF = (i64) 1e13;

int n , m;
int a[N];
i64 dp[N][N];

i64 solve(int i , int j){
        if(i >= n){
                return (j == m + 1 ? 0 : -INF);
        }
        auto &ret = dp[i][j];
        if(ret != -1){
                return ret;
        }
        return ret = max(solve(i + 1 , j) , solve(i + 1 , j + 1) + (1LL * j * a[i]));
}

int32_t main(){
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        cin >> n >> m;
        for(int i = 0 ; i < n ; ++i){
                cin >> a[i];
        }
        memset(dp , -1 , sizeof dp);
        cout << solve(0 , 1);
        return 0;
}
