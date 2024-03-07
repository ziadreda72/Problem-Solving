#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

void solveTC(){
        i64 x , n;
        cin >> x >> n;

        if (n == x) {
                cout << 1;
                return;
        }

        if (n == 1) {
                cout << x;
                return;
        }

        i64 ans = 1;
        for (i64 d = 2 ; d * d <= x ; ++d) {
                if (x % d == 0) {
                        i64 rem = x - (n * d);
                        if (rem >= 0 && (rem % d == 0)) {
                                ans = max(ans , d);
                        }
                        i64 d2 = x / d;
                        rem = x - (n * d2);
                        if (rem >= 0 && (rem % d2) == 0) {
                                ans = max(ans , d2);
                        }
                }
        }

        cout << ans;
}

int32_t main(){
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        
        int tc;
        cin >> tc;
        
        while (tc--){
                solveTC();
                cout << '\n';
        }
        
        return 0;
}
