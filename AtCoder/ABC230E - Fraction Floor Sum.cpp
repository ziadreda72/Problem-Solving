#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

int32_t main(){
        ios::sync_with_stdio(false);
        cin.tie(nullptr);

        i64 N;
        cin >> N;

        i64 ans = 0;

        for(i64 i = 1 ; i <= N ;){
                i64 lo = i , hi = N + 1;
                while(hi - lo > 1){
                        i64 mid = (lo + hi) / 2;
                        if((N / i) != (N / mid)){
                                hi = mid;
                        }else{
                                lo = mid;
                        }
                }
                ans += (N / i) * (lo - i + 1);
                i = lo + 1;
        }

        cout << ans;

        return 0;
}
