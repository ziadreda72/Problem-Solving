#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

int32_t main(){
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        
        int n , m , k;
        cin >> n >> m >> k;

        vector < i64 > a(n) , b(m);
        for(int i = 0 ; i < n ; ++i){
                cin >> a[i];
                if(i) a[i] += a[i - 1];
        }
        for(int i = 0 ; i < m ; ++i){
                cin >> b[i];
                if(i) b[i] += b[i - 1];
        }

        int ans = upper_bound(b.begin() , b.end() , k) - b.begin();
        for(int i = 0 ; i < n && a[i] <= k ; ++i){
                int j = upper_bound(b.begin() , b.end() , k - a[i]) - b.begin();
                ans = max(ans , i + j + 1);
        }

        cout << ans;
        
        return 0;
}
