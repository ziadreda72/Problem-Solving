#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

int32_t main(){
        ios::sync_with_stdio(false);
        cin.tie(nullptr);

        int N , X;
        cin >> N >> X;

        vector < array < int , 2 > > a(N);
        for(int i = 0 ; i < N ; ++i) cin >> a[i][0] >> a[i][1];

        vector < i64 > pref(N + 1 , 0LL);

        for(int i = 1 ; i <= N ; ++i){
                pref[i] = pref[i - 1] + (a[i - 1][0] + a[i - 1][1]);
        }

        i64 ans = INT64_MAX;
        for(int i = 1 ; i <= min(N , X) ; ++i){
                ans = min(ans , pref[i] + (1LL * (X - i) * a[i - 1][1]));
        }

        cout << ans;

        return 0;
}
