#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

const int N = 5005 , inf = 1e8;

vector < int > a , b;
int dp[N][N];

int solve(int i , int j){
        if(i == a.size())
                return 0;
        if(j == b.size())
                return inf;
        auto &ret = dp[i][j];
        if(~ret)
                return ret;
        return ret = min(solve(i , j + 1) , solve(i + 1 , j + 1) + abs(a[i] - b[j]));
}

int32_t main() {
        ios::sync_with_stdio(false);cin.tie(nullptr);
        cout.tie(nullptr);cout.precision(20);
        int n;
        cin >> n;
        for (int i = 0; i < n; ++i) {
                int x;
                cin >> x;
                if(x)
                        a.push_back(i);
                else
                        b.push_back(i);
        }
        memset(dp , -1 , sizeof dp);
        cout << solve(0 , 0);
        return 0;
}
