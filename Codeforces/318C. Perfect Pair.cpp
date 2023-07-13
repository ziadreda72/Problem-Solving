#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

i64 solve(i64 x , i64 y , i64 m){
        if(x >= m || y >= m)
                return 0;
        if(x <= 0 && y <= 0)
                return -1;
        i64 ret = 0;
        if(x < y)
                swap(x , y);
        if(y < 0)
                ret += (abs(y) + x - 1) / x , y += 1LL * ((abs(y) + x - 1) / x) * x;
        if (x < y)
                swap(x , y);
        while (x < m){
                y = y + x;
                if(x < y)
                        swap(x , y);
                ret++;
        }
        return ret;
}

int32_t main() {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        i64 x , y , m;
        cin >> x >> y >> m;
        cout << solve(x , y , m);
        return 0;
}
