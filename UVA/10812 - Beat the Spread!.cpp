#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

#define F first
#define S second

void solve() {
    unsigned x , y;
    cin >> x >> y;
    if((y > x) || ((x + y) & 1)){
        cout << "impossible";
    }else{
        cout << (x + y) / 2 << ' ' << x - ((x + y) / 2);
    }
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
