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
        int g = 0;
        for(int i = 0 ; i < n ; ++i){
                cin >> a[i];
                g = gcd(g , a[i]);
        }
        int ans = 0;
        for(auto x : a){
                x /= g;
                while(x % 2 == 0){
                        x /= 2;
                        ans++;
                }
                while (x % 3 == 0){
                        x /= 3;
                        ans++;
                }
                if(x != 1){
                        cout << -1;
                        return 0;
                }
        }
        cout << ans;
        return 0;
}
