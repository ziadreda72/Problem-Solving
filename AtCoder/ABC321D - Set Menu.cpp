#include <bits/stdc++.h>

using namespace std;
using i64 = long long;
using ld = long double;

#define F first
#define S second

int n , m;
i64 p;
vector < i64 > a , b , pref;

i64 get(i64 x){
        int lo = 0 , hi = m + 1;
        while(hi - lo > 1){
                int mid = (lo + hi) / 2;

                if(b[mid] + x <= p){
                        lo = mid;
                }else{
                        hi = mid;
                }
        }

        return 1LL * ((lo * x) + pref[lo] + (m - lo) * p);
}

int32_t main(){
        ios::sync_with_stdio(false);
        cin.tie(nullptr);

        cin >> n >> m >> p;

        a.resize(n + 1);
        b.resize(m + 1);
        pref.assign(m + 1 , 0);

        for(int i = 1 ; i <= n ; ++i) cin >> a[i];
        for(int i = 1 ; i <= m ; ++i) cin >> b[i];

        sort(b.begin() + 1 , b.end());
        for(int i = 1 ; i <= m ; ++i) pref[i] = pref[i - 1] + b[i];

        i64 ans = 0;
        for(int i = 1 ; i <= n ; ++i){
                ans += get(a[i]);
        }

        cout << ans;

        return 0;
}
