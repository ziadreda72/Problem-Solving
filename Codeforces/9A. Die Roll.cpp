#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

int32_t main(){
        ios::sync_with_stdio(false);
        cin.tie(nullptr);

        int x , y;
        cin >> x >> y;

        if(!x || !y || max(x , y) > 6) return cout << "0/1" , 0;

        int z = 6 - max(x , y) + 1;

        int g = gcd(z , 6);

        cout << z / g << '/' << 6 / g;

        return 0;
}
