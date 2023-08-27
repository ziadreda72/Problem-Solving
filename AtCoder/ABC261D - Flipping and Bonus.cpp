#include <bits/stdc++.h>

using namespace std;
using i64 = long long;
using ld = long double;

#define F first
#define S second

const int N = 5005;

int n , m;
int a[N];
i64 dp[N][N];
int C[N];

i64 solve(int i , int c){
        if(i >= n)
                return 0;
        auto &ret = dp[i][c];
        if(ret != -1)
                return ret;
        return ret = max(solve(i + 1 , 0) , solve(i + 1 , c + 1) + a[i] + C[c + 1]);
}

int32_t main(){
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        cin >> n >> m;
        for(int i = 0 ; i < n ; ++i)
                cin >> a[i];
        while(m--){
                int c , y;
                cin >> c >> y;
                C[c] = y;
        }
        memset(dp , -1 , sizeof dp);
        cout << solve(0 , 0);
        return 0;
}
