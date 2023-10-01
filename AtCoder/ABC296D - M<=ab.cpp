#include <bits/stdc++.h>

using namespace std;
using i64 = long long;
using ld = long double;

#define F first
#define S second

int32_t main(){
        ios::sync_with_stdio(false);
        cin.tie(nullptr);

        i64 N , M;
        cin >> N >> M;

        if(N < (M + N - 1) / N){
                cout << -1;
                return 0;
        }

        i64 lo = 0 , hi = 1E6 + 100;
        while(hi - lo > 1){
                i64 mid = (lo + hi) / 2;
                if(mid * mid >= M){
                        hi = mid;
                }else{
                        lo = mid;
                }
        }

        i64 ans = INT64_MAX;
        for(i64 a = 1 ; a <= hi ; ++a){
                i64 b = (M + a - 1) / a;
                if((1 <= a && a <= N) && (1 <= b && b <= N) && (a * b >= M)){
                        ans = min(ans , a * b);
                }
        }

        cout << ans;

        return 0;
}
