#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

int32_t main(){
        ios::sync_with_stdio(false);
        cin.tie(nullptr);

        i64 N;
        cin >> N;

        N += N;

        int ans = 0;
        for(i64 d = 1 ; d * d <= N ; ++d){
                if(N % d == 0){
                        auto d2 = N / d;
                        ans += ((d % 2) != (d2 % 2)) * 2;
                }
        }

        cout << ans;

        return 0;
}
