#include <bits/stdc++.h>

using namespace std;
using i64 = long long;
using ld = long double;

#define F first
#define S second

const int P = (int) 1e9 + 7;

int32_t main(){
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        int n , k;
        cin >> n >> k;
        vector < int > a(n);
        for(int i = 0 ; i < n ; ++i)
                cin >> a[i];
        for(int i = 0 ; i < n ; ++i)
                a.push_back(a[i]);
        i64 s = 0;
        for(int i = 0 ; i < n ; ++i)
                for(int j = 0 ; j < i ; ++j)
                        s += a[j] > a[i];
        i64 ans = 1LL * s * k % P;
        i64 x = 1LL * k * (k - 1) / 2;
        for(int i = 0 ; i < n ; ++i)
                for(int j = 0 ; j < n ; ++j)
                        if(a[i] > a[j])
                                ans = 1LL * (ans + x) % P;
        cout << ans;
        return 0;
}
