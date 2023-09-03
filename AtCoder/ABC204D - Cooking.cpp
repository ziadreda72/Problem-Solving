#include <bits/stdc++.h>

using namespace std;
using i64 = long long;
using ld = long double;

#define F first
#define S second

const int N = 105 , N2 = 1005;

int n , a[N] , dp[N][N * N2] , S;

int solve(int i , int s){
        if(i >= n)
                return max(s , S - s);
        auto &ret = dp[i][s];
        if(~ret)
                return ret;
        return ret = min(solve(i + 1 , s) , solve(i + 1 , s + a[i]));
}

int32_t main(){
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        cin >> n;
        for(int i = 0 ; i < n ; ++i){
                cin >> a[i];
                S += a[i];
        }       
        memset(dp , -1 , sizeof dp);
        cout << solve(0 , 0);
        return 0;
}
