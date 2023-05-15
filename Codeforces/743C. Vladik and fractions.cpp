#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

#define F first
#define S second

int32_t main() {
    ios::sync_with_stdio(false);cin.tie(nullptr);
    cout.tie(nullptr);cout.precision(20);
    i64 n;
    cin >> n;
    for (i64 x = 1; x <= 1e4 + 100; ++x) {
        for (i64 y = 1; y <= 1e4 + 100; ++y) {
            if(x == y)
                continue;
            i64 a = n * x * y;
            i64 b = 2 * x * y - n * x - n * y;
            if(b != 0){
                if(a % b == 0){
                    i64 z = a / b;
                    if(x == y || x == z || y == z || z <= 0 || z > 1e9)
                        continue;
                    cout << x << ' ' << y << ' ' << z;
                    return 0;
                }
            }
        }
    }
    cout << -1;
    return 0;
}
