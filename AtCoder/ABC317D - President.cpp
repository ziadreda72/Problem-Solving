#include <bits/stdc++.h>

using namespace std;
using i64 = long long;
using ld = long double;

#define F first
#define S second

const int N = 105 , N2 = (int) 1e5 + 5;
const i64 INF = (i64) 1e13;

int n , Z;
pair < pair < int , int > , int > a[N];
i64 dp[N][N2];

i64 solve(int i , int z){
        if(i >= n){
                return (z > (Z - z) ? 0 : INF);
        }
        auto &ret = dp[i][z];
        if(ret != -1){
                return ret;
        }
        ret = solve(i + 1 , z + (a[i].F.F > a[i].F.S ? a[i].S : 0));
        if(a[i].F.F < a[i].F.S){
                ret = min(ret , solve(i + 1 , z + a[i].S) + ((a[i].F.S - a[i].F.F + 1) / 2));
        }
        return ret;
}

int32_t main(){
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        cin >> n;
        for(int i = 0 ; i < n ; ++i){
                cin >> a[i].F.F >> a[i].F.S >> a[i].S;
                Z += a[i].S;
        }
        memset(dp , -1 , sizeof dp);
        cout << solve(0 , 0);
        return 0;
}
