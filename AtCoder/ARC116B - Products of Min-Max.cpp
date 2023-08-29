#include <bits/stdc++.h>

using namespace std;
using i64 = long long;
using ld = long double;

#define F first
#define S second

const int MOD = 998244353;

int32_t main(){
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        int n;
        cin >> n;
        vector < i64 > a(n);
        i64 ans = 0;
        for(int i = 0 ; i < n ; ++i){
                cin >> a[i];
                ans += a[i] * a[i] % MOD;
                ans %= MOD;
        }
        sort(a.begin() , a.end());
        i64 s = a[n - 1];
        for(int i = n - 2 ; i >= 0 ; --i){
                ans += a[i] * s % MOD;
                ans %= MOD;
                s = s * 2 + a[i];
                s %= MOD;
        }
        cout << ans % MOD;
        return 0;
}
