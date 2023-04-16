#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

#define F first
#define S second

int32_t main() {
    ios::sync_with_stdio(false);cin.tie(nullptr);
    cout.tie(nullptr);cout.precision(20);
    i64 n;
    while (cin >> n){
        cout << (n * (n + 1) / 2) * (n * (n + 1) / 2) << '\n';
    }
    return 0;
}
