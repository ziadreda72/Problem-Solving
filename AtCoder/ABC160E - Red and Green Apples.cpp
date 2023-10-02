#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

int32_t main(){
        ios::sync_with_stdio(false);
        cin.tie(nullptr);

        int x , y , n , n2 , n3;
        cin >> x >> y >> n >> n2 >> n3;

        vector < int > a(n) , b(n2) , c(n3);
        for(int i = 0 ; i < n ; ++i) cin >> a[i];
        for(int i = 0 ; i < n2 ; ++i) cin >> b[i];
        for(int i = 0 ; i < n3 ; ++i) cin >> c[i];

        sort(a.begin() , a.end());
        sort(b.begin() , b.end());
        
        int tot = x + y;

        while(x--){
                c.push_back(a.back());
                a.pop_back();
        }

        while(y--){
                c.push_back(b.back());
                b.pop_back();
        }

        sort(c.begin() , c.end());
        
        i64 ans = 0;
        while(tot--){
                ans += c.back();
                c.pop_back();
        }

        cout << ans;

        return 0;
}
