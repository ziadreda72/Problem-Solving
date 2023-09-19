#include <bits/stdc++.h>

using namespace std;
using i64 = long long;
using ld = long double;

#define F first
#define S second

void solveTC(){
        int n;
        cin >> n;

        vector < int > a(n);
        for(int i = 0 ; i < n ; ++i) cin >> a[i];
        for(int i = n - 2 ; i >= 0 ; --i) a[i] = min(a[i] , a[i + 1]);

        int k;
        cin >> k;

        vector < int > ans(n);
        int x = k / a[0] , y = k % a[0];
        ans[0] = x;
        for(int i = 1 ; i < n ; ++i){
                if(a[i] == a[i - 1]){
                        ans[i] = ans[i - 1];
                        continue;
                }
                int z = min(ans[i - 1] , y / (a[i] - a[i - 1]));
                ans[i] += z;
                y -= (a[i] - a[i - 1]) * z;
        }

        for(auto x : ans) cout << x << ' ';
}

int32_t main(){
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        int tc;
        cin >> tc;
        while (tc--){
                solveTC();
                cout << '\n';
        }
        return 0;
}
