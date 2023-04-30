#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

#define F first
#define S second

int cnt;
int n , k;
map < i64 , bool > mp , vis;

void dfs(i64 x){
    vis[x] = true;
    i64 y = 1LL * x * k;
    if(mp.contains(y) && !vis.contains(y)){
        cnt++;
        dfs(y);
    }
}

int32_t main() {
    ios::sync_with_stdio(false);cin.tie(nullptr);
    cout.tie(nullptr);cout.precision(20);
    cin >> n >> k;
    vector < i64 > a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        mp[a[i]] = 1;
    }
    sort(a.begin(), a.end());
    int ans = n;
    for (int i = 0; i < n; ++i) {
        if(vis.contains(a[i])) continue;
        cnt = 1;
        dfs(a[i]);
        ans -= cnt >> 1;
    }
    cout << ans;
    return 0;
}
