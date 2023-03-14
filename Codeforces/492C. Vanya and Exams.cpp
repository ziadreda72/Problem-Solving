#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

#define F first
#define S second

int32_t main()
{
    ios::sync_with_stdio(false);cin.tie(nullptr);
    cout.tie(nullptr);cout.precision(20);
    i64 n , r , avg;
    cin >> n >> r >> avg;
    vector < pair < i64 , i64 > > a(n);
    i64 s = 0;
    for (int i = 0; i < n; ++i) {
        cin >> a[i].F >> a[i].S;
        s += a[i].F;
    }
    if(s >= 1LL * avg * n){
        cout << 0;
        return 0;
    }
    i64 k = (1LL * avg * n) - s;
    sort(a.begin(), a.end() , [](pair < i64 , i64 > a , pair < i64 , i64 > b){
       if(a.S == b.S){
           return a.F > b.F;
       }
       return a.S > b.S;
    });
    i64 ans = 0;
    while (k && !a.empty()){
        int x = min(k , r - a.back().F);
        k -= x;
        ans += x * a.back().S;
        a.pop_back();
    }
    cout << ans;
    return 0;
}
