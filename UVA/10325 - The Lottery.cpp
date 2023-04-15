#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

#define F first
#define S second

i64 lcm(i64 a , i64 b){
    return a * b / __gcd(a , b);
}

int32_t main() {
    ios::sync_with_stdio(false);cin.tie(nullptr);
    cout.tie(nullptr);cout.precision(20);
    i64 n;
    int m;
    while (cin >> n >> m){
        vector < int > a(m);
        for (int i = 0; i < m; ++i) {
            cin >> a[i];
        }
        i64 ans = 0;
        for (int msk = 1; msk < (1 << m); ++msk) {
            i64 x = 1;
            bool ok = true;
            for (int i = 0; i < m; ++i) {
                if((1 << i) & msk){
                    if(lcm(x , a[i]) > n){
                        ok = false;
                        break;
                    }
                    x = lcm(x , a[i]);
                }
            }
            if(!ok) continue;
            if(__builtin_popcount(msk) & 1){
                ans += n / x;
            }else{
                ans -= n / x;
            }
        }
        cout << ans << '\n';
    }
    return 0;
}
