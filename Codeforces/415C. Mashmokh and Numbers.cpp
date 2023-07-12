#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

int32_t main() {
        ios::sync_with_stdio(false);cin.tie(nullptr);
        cout.tie(nullptr);cout.precision(20);
        int n , k;
        cin >> n >> k;
        int n2 = n / 2;
        if(n2 > k || (n2 == 0 && k)){
                cout << -1;
                return 0;
        }
        if(k == n2){
                for (int i = 1; i <= n; ++i) {
                        cout << i << ' ';
                }
                return 0;
        }
        int n3 = n2 - 1;
        int x = (int) 1e9 - 10;
        while (n3--){
                cout << x << ' ' << x - 1 << ' ';
                k--;
                x -= 2;
                n -= 2;
        }
        n -= 2;
        cout << k << ' ' << 2 * k << ' ';
        if(n){
                cout << (int) 1e9;
        }
        return 0;
}
