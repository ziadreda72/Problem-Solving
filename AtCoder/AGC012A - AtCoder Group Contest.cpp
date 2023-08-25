#include <bits/stdc++.h>

using namespace std;
using i64 = long long;
using ld = long double;

#define F first
#define S second

int32_t main(){
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        int n;
        cin >> n;
        vector < int > a(3 * n);
        for(int i = 0 ; i < 3 * n ; ++i)
                cin >> a[i];
        sort(a.begin() , a.end());
        i64 ans = 0;
        int i = 3 * n - 2;
        while(n--)
                ans += a[i] , i -= 2;
        cout << ans;
        return 0;
}
