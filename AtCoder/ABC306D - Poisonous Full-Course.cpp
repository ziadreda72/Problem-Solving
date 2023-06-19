#include <bits/stdc++.h>

using i64 = long long;

const int N = (int) 3e5 + 10;

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
                ret = std::max(ret , solve(i + 1 , !a[i][0]) + a[i][1]);
        else if(!a[i][0])
                ret = std::max(ret , solve(i + 1 , 1) + a[i][1]);
        return ret;
}

int32_t main() {
        std::ios::sync_with_stdio(false);
        std::cin.tie(nullptr);
        std::cout.tie(nullptr);
        std::cout.precision(20);
        std::cin >> n;
        for (int i = 0; i < n; ++i) {
                std::cin >> a[i][0] >> a[i][1];
        }
        std::cout << solve(0 , 1);
        return 0;
}
