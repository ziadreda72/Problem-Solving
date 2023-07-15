#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

string s;
i64 dp[65][65];

i64 solve(int l , int r){
        if(l == r)
                return 1;
        if(r - l == 1)
                return 2 + (s[l] == s[r]);
        auto &ret = dp[l][r];
        if(~ret)
                return ret;
        ret = 0;
        if(s[l] == s[r])
                ret += 1 + solve(l + 1 , r - 1);
        ret += solve(l + 1 , r);
        ret += solve(l , r - 1);
        ret -= solve(l + 1 , r - 1);
        return ret;
}

int32_t main() {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        int tc;
        cin >> tc;
        while (tc--){
                cin >> s;
                memset(dp , -1 , sizeof dp);
                cout << solve(0 , (int) s.size() - 1) << '\n';
        }
        return 0;
}
