#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

#define F first
#define S second

int32_t main() {
    ios::sync_with_stdio(false);cin.tie(nullptr);
    cout.tie(nullptr);cout.precision(20);
    double n;
    while (cin >> n , n){
        double a = floor(pow(n , 1/3.0) + 1e-6);
        double dx = (n - a * a * a) / 3.0 / a / a;
        cout << fixed << setprecision(4);
        cout << a + dx << '\n';
    }
    return 0;
}
