#include <bits/stdc++.h>

using namespace std;
using i64 = long long;
using ld = long double;

#define F first
#define S second

int32_t main(){
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        i64 a , b;
        cin >> a >> b;
        i64 ans = 1;
        for(i64 d = 2 ; d * d <= max(a , b) ; ++d){
                bool aa = 0 , bb = 0;
                while(a % d == 0){
                        a /= d;
                        aa = 1;
                }
                while(b % d == 0){
                        b /= d;
                        bb = 1;
                }
                ans += aa && bb;
        }
        ans += a > 1 && a == b;
        cout << ans;
        return 0;
}
