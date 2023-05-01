#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

#define F first
#define S second

const int N = 1005;

int n;
string s;
int dp[N][N] , vis[N][N] , id;

int solve(int i , int j){
    if(i >= j) return 0;
    auto &ret = dp[i][j];
    if(vis[i][j] == id) return ret;
    vis[i][j] = id;
    return ret = min({solve(i + 1 , j - 1) + (s[i] != s[j]) , solve(i + 1 , j) + 1 , solve(i , j - 1) + 1});
}

void solveTC() {
    cin >> s;
    n = (int) s.size();
    id++;
    cout << "Case " << id << ": " << solve(0 , n - 1);
}

int32_t main() {
    ios::sync_with_stdio(false);cin.tie(nullptr);
    cout.tie(nullptr);cout.precision(20);
    int tc = 1;
    cin >> tc;
    while(tc--){
        solveTC();
        cout << '\n';
    }
    return 0;
}
