#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

#define F first
#define S second

const int N = 105;

string s , t;
int dp[N][N] , vis[N][N] , id;

int solve(int i , int j){
    if(i >= (int) s.size() || j >= (int) t.size())
        return 0;
    int &ret = dp[i][j];
    if(vis[i][j] == id) return ret;
    vis[i][j] = id;
    if(s[i] == t[j]){
        return ret = 1 + solve(i + 1 , j + 1);
    }
    return ret = max(solve(i + 1 , j) , solve(i , j + 1));
}

int32_t main() {
    ios::sync_with_stdio(false);cin.tie(nullptr);
    cout.tie(nullptr);cout.precision(20);
    int tc = 1;
    while (getline(cin , s) && s[0] != '#'){
        getline(cin , t);
        id++;
        cout << "Case #" << tc++ << ": you can visit at most " << solve(0, 0) << " cities.\n";

    }
    return 0;
}
