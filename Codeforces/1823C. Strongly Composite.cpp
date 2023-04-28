#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

#define F first
#define S second

void solve() {
    int n;
    cin >> n;
    map < int , int > mp;
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        for (int j = 2; j * j <= x; ++j) {
            while (x % j == 0){
                mp[j]++;
                x /= j;
            }
        }
        if(x > 1) mp[x]++;
    }
    int ans = 0 , r = 0;
    for(auto [_ , x] : mp) {
        ans += x / 2;
        r += x % 2;
    }
    cout << ans + r / 3;
}

int32_t main() {
    ios::sync_with_stdio(false);cin.tie(nullptr);
    cout.tie(nullptr);cout.precision(20);
    int tc = 1;
    cin >> tc;
    while(tc--){
        solve();
        cout << '\n';
    }
    return 0;
}
