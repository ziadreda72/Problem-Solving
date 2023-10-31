#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

int32_t main(){
        ios::sync_with_stdio(false);
        cin.tie(nullptr);

        int N;
        cin >> N;

        vector < int > a(N);
        for(int i = 0 ; i < N ; ++i) cin >> a[i];
        sort(a.begin() , a.end());

        vector < int > b(N);
        for(int i = 0 ; i < N ; ++i) cin >> b[i];

        vector < int > c(N);
        for(int i = 0 ; i < N ; ++i) cin >> c[i];
        sort(c.begin() , c.end());

        i64 ans = 0;

        for(auto j : b){
                int i = lower_bound(a.begin() , a.end() , j) - a.begin();
                int k = upper_bound(c.begin() , c.end() , j) - c.begin();

                ans += 1LL * i * (N - k);
        }

        cout << ans;

        return 0;
}
