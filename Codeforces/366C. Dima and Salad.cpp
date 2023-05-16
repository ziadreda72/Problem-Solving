#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

#define F first
#define S second

const int N = 105 , OO = (int) -1e8;

int n , k;
int dp[N][N * N];
vector < pair < int , int > > v;

int solve(int i , int s){
    if(i >= n){
        if(s == 0)
            return 0;
        return OO;
    }
    auto &ret = dp[i][s];
    if(~ret)
        return ret;
    ret = solve(i + 1 , s);
    if(s + v[i].F >= 0)
        ret = max(ret , solve(i + 1 , s + v[i].F) + v[i].S);
    return ret;
}

int32_t main() {
    ios::sync_with_stdio(false);cin.tie(nullptr);
    cout.tie(nullptr);cout.precision(20);
    cin >> n >> k;
    v.resize(n);
    for (int i = 0; i < n; ++i) {
        cin >> v[i].F;
        v[i].S = v[i].F;
    }
    for (int i = 0; i < n; ++i) {
        int b;
        cin >> b;
        v[i].F -= b * k;
    }
    sort(v.rbegin(), v.rend());
    memset(dp , -1 , sizeof dp);
    int sol = solve(0 , 0);
    if(sol <= 0)
        sol = -1;
    cout << sol;
    return 0;
}
