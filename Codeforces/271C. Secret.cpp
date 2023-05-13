#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

#define F first
#define S second

int32_t main() {
    ios::sync_with_stdio(false);cin.tie(nullptr);
    cout.tie(nullptr);cout.precision(20);
    int n , k;
    cin >> n >> k;
    if(n == k || n / k <= 2){
        cout << -1;
        return 0;
    }
    set < int > st[k];
    int l = 0 , r = n - 1;
    int rem = n % k;
    while (rem--)
        st[0].insert(l++);
    for (int i = k - 1; i >= 0; --i) {
        st[i].insert(r--);
    }
    int cur = 0;
    int cnt = 0;
    for (int i = l; i <= r; ++i) {
        st[cur].insert(i);
        cnt++;
        if(cnt == (n / k) - 1)
            cur++ , cnt = 0;
    }
    vector < int > ans(n);
    for (int i = 0; i < k; ++i) {
        for(auto x : st[i])
            ans[x] = i + 1;
    }
    for (int i = 0; i < n; ++i) {
        cout << ans[i] << ' ';
    }
    return 0;
}
