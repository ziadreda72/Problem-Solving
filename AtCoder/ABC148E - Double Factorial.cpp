#include <bits/stdc++.h>

using namespace std;
using i64 = long long;
using ld = long double;

#define F first
#define S second

int32_t main(){
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        i64 n;
        cin >> n;
        if(n & 1){
                cout << 0;
                return 0;
        }
        i64 ans = 0;
        while(n){
                ans += n / 10;
                n /= 5;
        }
        cout << ans;
        return 0;
}
