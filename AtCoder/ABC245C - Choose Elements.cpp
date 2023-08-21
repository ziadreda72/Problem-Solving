#include <bits/stdc++.h>

using namespace std;
using i64 = long long;
using i128 = __int128;
using ld = long double;

const int N = (int) 2e5 + 5;

int n , k;
int a[N][2];
bool dp[N][2] , vis[N][2];

bool solve(int i , int j){
        if(i >= n - 1)
                return 1;
        auto &ret = dp[i][j];
        if(vis[i][j])
                return ret;
        vis[i][j] = 1;
        ret = 0;
        for(auto x : {0 , 1}){
                if(abs(a[i][j] - a[i + 1][x]) <= k)
                        ret |= solve(i + 1 , x);
        }
        return ret;
}

int32_t main(){
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        cin >> n >> k;
        for(int i = 0 ; i < n ; ++i)
                cin >> a[i][0];
        for(int i = 0 ; i < n ; ++i)
                cin >> a[i][1];
        cout << (solve(0 , 1) || solve(0 , 0) ? "Yes" : "No");
}
