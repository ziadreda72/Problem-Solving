#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

int32_t main(){
        ios::sync_with_stdio(false);
        cin.tie(nullptr);

        i64 N;
        cin >> N;

        map < i64 , int > mp;

        for(i64 d = 2 ; d * d <= N ; ++d){
                while(N % d == 0){
                        ++mp[d];
                        N /= d;
                }
        }

        if(N > 1) ++mp[N];

        int ans = 0;

        for(auto [_ , x] : mp){
                int lo = 1 , hi = 1000;
                while(hi - lo > 1){
                        int mid = (lo + hi) / 2;
                        if(mid * (mid + 1) <= 2 * x){
                                lo = mid;
                        }else{
                                hi = mid;
                        }
                }
                ans += lo;
        }

        cout << ans;

        return 0;
}
