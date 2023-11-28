#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

int32_t main(){
        ios::sync_with_stdio(false);
        cin.tie(nullptr);

        int N;
        cin >> N;

        int ans = 0;
        for(int i = 0 ; i < N ; ++i){
                int x;
                cin >> x;
                
                ans = gcd(ans , x);
        }

        cout << ans;

        return 0;
}
