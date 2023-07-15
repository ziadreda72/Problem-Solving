#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

long double m , w , c;
long double dp[1010][110];
int id , vis[1010][110];

long double solve(int men , int rem){
        if(rem == 0)
                return (men % 2) == 0;
        auto &ret = dp[men][rem];
        if(vis[men][rem] == id)
                return ret;
        vis[men][rem] = id;
        ret = 0;
        return ret = (m / (m + w)) * solve(men + 1 , rem - 1) + (w / (m + w)) * solve(men , rem - 1);
}

int32_t main() {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.precision(20);
        while (cin >> m >> w >> c && (m || w)){
                id++;
                cout << solve(0 , (int) c) << '\n';
        }
	return 0;
}
