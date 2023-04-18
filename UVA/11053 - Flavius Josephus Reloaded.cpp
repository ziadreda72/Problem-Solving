#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

#define F first
#define S second

int MOD;

int add(int a , int b) {
    return ( 1LL * (a % MOD ) + (b % MOD ) ) % MOD;
}

int sub(int a , int b) {
    int ret = ( ( a - b ) % MOD + MOD ) % MOD;
    return ret;
}

int mul(int a , int b) {
    return ( 1LL * (a % MOD ) * (b % MOD ) ) % MOD;
}

int POW(int a , int b) {
    int ret = 1;
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
    int n , a , b;
    while (cin >> n , n){
        cin >> a >> b;
        MOD = n;
        map < int , int > mp;
        int x = 0;
        int ans = n;
        while (true){
            int nxt = add(mul(a , POW(x , 2)) , b);
            int &y = mp[nxt];
            y++;
            if(y == 2) ans--;
            if(y == 3) break;
            x = nxt;
        }
        cout << ans << '\n';
    }
    return 0;
}
