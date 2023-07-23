#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

int32_t main() {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        int n , m;
        i64 d;
        cin >> n >> m >> d;
        vector < i64 > a(n) , b(m);
        for(auto &i : a) cin >> i;
        for(auto &i : b) cin >> i;
        sort(a.rbegin(), a.rend());
        sort(b.begin(), b.end());
        for(auto x : a){
                int l = lower_bound(b.begin(), b.end() , x - d) - b.begin();
                int r = upper_bound(b.begin(), b.end() , x + d) - b.begin();
                if(r - l == 0)
                        continue;
                cout << x + b[--r];
                return 0;
        }
        cout << -1;
        return 0;
}
