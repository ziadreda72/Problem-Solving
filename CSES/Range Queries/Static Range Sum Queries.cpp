#include "bits/stdc++.h"

using namespace std;
using i64 = long long;

int SQRT(int x){
        int lo = 0 , hi = 1;
        while(hi * hi <= x){
                hi <<= 1;
        }

        while(hi - lo > 1){
                int mid = (lo + hi) >> 1;
                if(mid * mid >= x){
                        hi = mid;
                }else{
                        lo = mid;
                }
        }
        
        return hi;
}

int32_t main(){
        ios::sync_with_stdio(false);
        cin.tie(nullptr);

        int n , q;
        cin >> n >> q;
        int B = SQRT(n);
        vector < i64 > a(n) , b(B , 0LL);
        for(int i = 0 ; i < n ; ++i){
                cin >> a[i];
                b[i / B] += a[i];
        }

        while(q--){
                int l , r;
                cin >> l >> r;
                --l , --r;
                i64 ans = 0;
                for(int i = l ; i <= r ;){
                        if(i % B == 0 && i + B - 1 <= r){
                                ans += b[i / B];
                                i += B;
                        }else{
                                ans += a[i++];
                        }
                }
                cout << ans << '\n';
        }

        return 0;
}
