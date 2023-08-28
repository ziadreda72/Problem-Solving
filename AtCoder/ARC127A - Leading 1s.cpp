#include <bits/stdc++.h>

using namespace std;
using i64 = long long;
using ld = long double;

#define F first
#define S second

int32_t main(){
        ios::sync_with_stdio(false);
        cin.tie(nullptr);

        i64 n;
        cin >> n;

        i64 ans = 0;
        for(int x = 1 ; x <= 16 ; ++x){
                i64 lo = 0;
                for(int i = 0 ; i < x ; ++i)
                        lo = 10 * lo + 1;
                i64 hi = lo;
                for(int i = x ; i <= 16 ; ++i){
                        if(lo <= n)
                                ans += min(n , hi) - lo + 1;
                        lo *= 10;
                        hi = 10 * hi + 9;
                }
        }

        cout << ans;

        return 0;
}
