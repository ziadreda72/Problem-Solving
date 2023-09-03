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
        vector < int > a(n) , prf(n , 0) , suf(n , 0);
        for(int i = 0 ; i < n ; ++i){
                cin >> a[i];
                if(i == 0){
                        prf[i] = a[i];
                }
                else{
                        prf[i] = gcd(prf[i - 1] , a[i]);
                }
        }
        for(int i = n - 1 ; i >= 0 ; --i){
                if(i == n - 1){
                        suf[i] = a[i];
                }
                else{
                        suf[i] = gcd(suf[i + 1] , a[i]);
                }
        }
        int ans = max(suf[1] , prf[n - 2]);
        for(int i = 1 ; i + 1 < n ; ++i){
                ans = max(ans , gcd(prf[i - 1] , suf[i + 1]));
        }
        cout << ans;
        return 0;
}
