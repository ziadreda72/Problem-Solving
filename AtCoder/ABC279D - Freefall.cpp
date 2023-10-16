#include <bits/stdc++.h>

using namespace std;
using i64 = long long;
using ld = long double;

int32_t main(){
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.precision(20);
        
        i64 A , B;
        cin >> A >> B;

        auto f = [&](i64 x){
                return (ld) A / sqrtl(x + 1) + (ld) B * x;
        };

        i64 l = 0 , r = A / B;
        while(r - l >= 3){
                i64 m1 = l + (r - l) / 3;
                i64 m2 = r - (r - l) / 3;
                if(f(m1) > f(m2)){
                        l = m1;
                }else{
                        r = m2;
                }
        }

        ld ans = A;
        for(i64 i = l ; i <= r ; ++i){
                ans = min(ans , f(i));
        }

        cout << ans;

        return 0;
}
