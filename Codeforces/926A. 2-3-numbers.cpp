#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

const i64 MAX = 2e9;

int32_t main() {
    ios::sync_with_stdio(false);cin.tie(nullptr);
    cout.tie(nullptr);cout.precision(20);
    set < i64 > st;
    for (int i = 0;; ++i) {
        for (int j = 0;; ++j) {
            if((1LL * (1LL << i) * (pow(3 , j))) > MAX)
                break;
            st.insert(((1 << i) * (pow(3 , j))));
        }
        if((1LL << i) > MAX)
            break;
    }
    i64 l , r;
    cin >> l >> r;
    auto it = st.lower_bound(l);
    i64 ans = 0;
    while (it != st.end() && *it <= r){
        ans++;
        it++;
    }
    cout << ans;
    return 0;
}
