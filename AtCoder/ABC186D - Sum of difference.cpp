#include <bits/stdc++.h>

using namespace std;
using i64 = long long;
using i128 = __int128;
using ld = long double;

#define F first
#define S second

int32_t main(){
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        int n;
        cin >> n;
        vector < int > a(n);
        for(int i = 0 ; i < n ; ++i)
                cin >> a[i];
        sort(a.begin() , a.end());
        i64 s = 0 , ans = 0;
        for(int i = 0 ; i < n ; ++i){
                ans += 1LL * (1LL * i * a[i] - s);
                s += a[i];
        }
        cout << ans;
        return 0;
}
