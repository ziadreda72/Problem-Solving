#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

int32_t main(){
        ios::sync_with_stdio(false);
        cin.tie(nullptr);

        i64 n , k;
        cin >> n >> k;

        vector < i64 > a(n);
        for(int i = 0 ; i < n ; ++i) cin >> a[i];

        sort(a.begin() , a.end());

        auto good = [&](i64 x){
                i64 ret = 0;

                for(int i = n / 2 ; i < n ; ++i){
                        ret += max(0LL , x - a[i]);
                }

                return ret <= k;
        };

        i64 lo = a[n / 2] , hi = (i64) 1e11;
        while(hi - lo > 1){
                i64 mid = (lo + hi) / 2;
                if(good(mid)){
                        lo = mid;
                }else{
                        hi = mid;
                }
        }

        cout << lo;

        return 0;
}
