#include <bits/stdc++.h>

using namespace std;
using i64 = long long;
using ld = long double;

int32_t main(){
        ios::sync_with_stdio(false);
        cin.tie(nullptr);

        ld a , b , c , d;
        cin >> a >> b >> c >> d;

        cout << fixed << setprecision(20) << ld(a / b / (1 - (1 - a / b) * (1 - c / d)));

        return 0;
}
