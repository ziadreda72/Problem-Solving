#include <bits/stdc++.h>

using namespace std;
using i64 = long long;
using ld = long double;

ld P(ld a , int b){
        ld ret = (ld) 1.0;
        while(b){
                if(b & 1) ret = ret * a;
                a *= a;
                b >>= 1;
        }
        return ret;
}

int32_t main(){
        ios::sync_with_stdio(false);
        cin.tie(nullptr);

        int m , n;
        cin >> m >> n;

        ld ans = (ld) 0.0;

        for(int i = 1 ; i <= m ; ++i){
                ans += i * (P((ld) i / m , n) - P((ld) (i - 1) / m , n));
        }

        cout << fixed << setprecision(20) << ans;

        return 0;
}
