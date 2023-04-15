#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

#define F first
#define S second

const i64 MOD = (int) 2e9 + 11;

i64 mul(i64 a , i64 b) {
    return ( 1LL * (a % MOD ) * (b % MOD ) ) % MOD;
}

i64 POW(i64 a , i64 b) {
    i64 ret = 1;
    while (b){
        if( b & 1 ) ret = mul(ret , a);
        a = mul(a , a);
        b >>= 1;
    }
    return ret;
}

int32_t main() {
    ios::sync_with_stdio(false);cin.tie(nullptr);
    cout.tie(nullptr);cout.precision(20);
    int t;
    cin >> t;
    for (int i = 1; i <= t; ++i) {
        int n;
        cin >> n;
        cout << "Case #" << i << ": ";
        if(n <= 1){
            cout << n << '\n';
            continue;
        }
        cout << POW(n , n - 2) << '\n';
    }
    return 0;
}
