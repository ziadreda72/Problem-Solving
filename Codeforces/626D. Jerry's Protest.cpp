#include <bits/stdc++.h>

using namespace std;
using i64 = long long;
using ld = long double;

int32_t main(){
        ios::sync_with_stdio(false);
        cin.tie(nullptr);

        int n;
        cin >> n;

        vector < int > a(n);
        for(int i = 0 ; i < n ; ++i) cin >> a[i];

        sort(a.begin() , a.end());

        vector < int > cnt(5000);
        for(int i = 0 ; i < n ; ++i) {
                for(int j = 0 ; j < i ; ++j) {
                        ++cnt[a[i] - a[j]];
                }
        }        

        vector < int > suf(5000);
        suf.back() = cnt.back();
        for(int i = 4998 ; i >= 0 ; --i) {
                suf[i] += suf[i + 1] + cnt[i];
        }

        i64 c = 0;
        for(int i = 1 ; i < 5000 ; ++i) {
                for(int j = 1 ; j < 5000 ; ++j) {
                     if(i + j + 1 >= 5000) continue;
                     c += 1LL * cnt[i] * cnt[j] * suf[i + j + 1];   
                }
        }

        i64 all = 1LL * n * (n - 1) / 2;
        all = all * all * all;

        ld ans = (ld) c / (ld) all;

        cout << fixed << setprecision(20) << ans;

        return 0;
}
