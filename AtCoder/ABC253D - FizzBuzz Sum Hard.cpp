#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

int32_t main(){
        ios::sync_with_stdio(false);
        cin.tie(nullptr);

        i64 N , A , B;
        cin >> N >> A >> B;

        i64 X = N / A , Y = N / B , L = lcm(A , B) , Z = N / L;

        auto calc = [&](i64 A , i64 X){
                return (1LL * A * X * (X + 1) / 2);
        };

        i64 ans = (1LL * N * (N + 1) / 2) - calc(A , X) - calc(B , Y) + calc(L , Z);

        cout << ans;

        return 0;
}
