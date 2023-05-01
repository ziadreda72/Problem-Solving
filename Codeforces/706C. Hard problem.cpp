#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

#define F first
#define S second

const int N = (int) 1e5 + 10;
const i64 OO = (i64) 1e18;

int n;
string a[N][2];
i64 c[N] , dp[N][2];

i64 solve(int i , int lst){
    if(i >= n) return 0;
    i64 &ret = dp[i][lst];
    if(ret != -1) return ret;
    ret = OO;
    if(a[i][0] >= a[i - 1][lst]) ret = min(ret , solve(i + 1 , 0));
    if(a[i][1] >= a[i - 1][lst]) ret = min(ret , solve(i + 1 , 1) + c[i]);
    return ret;
}

int32_t main() {
    ios::sync_with_stdio(false);cin.tie(nullptr);
    cout.tie(nullptr);cout.precision(20);
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> c[i];
    }
    for (int i = 0; i < n; ++i) {
        string s;
        cin >> s;
        a[i][0] = s;
        reverse(s.begin(), s.end());
        a[i][1] = s;
    }
    memset(dp , -1 , sizeof dp);
    i64 sol = min(solve(1 , 0) , solve(1 , 1) + c[0]);
    if(sol > (i64) 1e17) sol = -1;
    cout << sol;
    return 0;
}
