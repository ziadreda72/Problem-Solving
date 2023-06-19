#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

const int N = (int) 3e5 + 10;
const i64 inf = (i64) -1e16;

int n , a[N][2];
i64 dp[N][2];
bool vis[N][2];

i64 solve(int i , bool cur){
        if(i >= n)
                return 0;
        auto &ret = dp[i][cur];
        if(vis[i][cur])
                return ret;
        vis[i][cur] = 1;
        ret = solve(i + 1 , cur);
        if(cur)
                ret = max(ret , solve(i + 1 , !a[i][0]) + a[i][1]);
        else if(!a[i][0])
                ret = max(ret , solve(i + 1 , 1) + a[i][1]);
        return ret;
}

int32_t main() {
        ios::sync_with_stdio(false);cin.tie(nullptr);
        cout.tie(nullptr);cout.precision(20);
        cin >> n;
        for (int i = 0; i < n; ++i) {
                cin >> a[i][0] >> a[i][1];
        }
        cout << solve(0 , 1);
        return 0;
}
