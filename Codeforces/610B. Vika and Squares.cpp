#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

#define F first
#define S second

int32_t main() {
    ios::sync_with_stdio(false);cin.tie(nullptr);
    cout.tie(nullptr);cout.precision(20);
    int n;
    cin >> n;
    vector < int > a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    int x = *min_element(a.begin(), a.end());
    i64 ans = 1LL * x * n;
    for (int i = 0; i < n; ++i) {
        a[i] -= x;
    }
    auto a2 = a;
    for(auto i : a2) a.push_back(i);
    int mx = 0 , cnt = 0;
    for (int i = 0; i < (int) a.size(); ++i) {
        if(a[i] == 0){
            cnt = 0;
            continue;
        }
        cnt++;
        mx = max(mx , cnt);
    }
    ans += mx;
    cout << ans;
    return 0;
}
