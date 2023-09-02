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
        vector < int > a(n);
        for(int i = 0 ; i < n ; ++i){
                cin >> a[i];
        }
        i64 ans = 0;
        for(int i = 1 ; i < n ; ++i){
                if(a[i] >= a[i - 1]){
                        continue;
                }
                ans += a[i - 1] - a[i];
                a[i] = a[i - 1];
        }
        cout << ans;
        return 0;
}
