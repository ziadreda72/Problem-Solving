#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

#define F first
#define S second

int lcm(int a , int b){
    return a * b / __gcd(a , b);
}

int32_t main() {
    ios::sync_with_stdio(false);cin.tie(nullptr);
    cout.tie(nullptr);cout.precision(20);
    int n , m;
    while (cin >> n >> m && n){
        vector < int > a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        while (m--){
            int x;
            cin >> x;
            int mx = 0 , mn = INT32_MAX;
            for (int i = 0; i < n; ++i) {
                for (int j = i + 1; j < n; ++j) {
                    for (int k = j + 1; k < n; ++k) {
                        for (int l = k + 1; l < n; ++l) {
                            int LCM = lcm(a[i] , a[j]);
                            LCM = lcm(LCM , a[k]);
                            LCM = lcm(LCM , a[l]);
                            int y = (x / LCM) * LCM;
                            mx = max(mx , y);
                            if(y < x) y += LCM;
                            mn = min(mn , y);
                        }
                    }
                }
            }
            cout << mx << ' ' << mn << '\n';
        }
    }
    return 0;
}
