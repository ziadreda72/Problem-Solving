#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

#define F first
#define S second

int32_t main() {
    ios::sync_with_stdio(false);cin.tie(nullptr);
    cout.tie(nullptr);cout.precision(20);
    int n , k;
    cin >> n >> k;
    vector < int > a(n);
    vector < pair < int , int > > v;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        if(a[i] % 10 == 0)
            continue;
        v.emplace_back(10 - a[i] % 10 , i);
    }
    sort(v.begin(), v.end());
    for(auto [x , i] : v){
        a[i] += min(k , x);
        k -= min(k , x);
    }
    for (int i = 0; i < n; ++i) {
        while (a[i] + 10 <= 100){
            a[i] += min(10 , k);
            k -= min(10 , k);
            if(!k)
                break;
        }
        if(!k)
            break;
    }
    int ans = 0;
    for(auto x : a)
        ans += x / 10;
    cout << ans;
    return 0;
}
