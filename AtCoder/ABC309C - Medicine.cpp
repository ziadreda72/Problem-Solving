#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

int32_t main() {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        int n , k;
        cin >> n >> k;
        map < int , i64 > mp;
        i64 sum = 0;
        for (int i = 0; i < n; ++i) {
                int a , b;
                cin >> a >> b;
                mp[a] += b;
                sum += b;
        }
        if(sum <= k){
                cout << 1;
                return 0;
        }
        for(auto [a , b] : mp){
                sum -= b;
                if(sum <= k){
                        cout << a + 1;
                        return 0;
                }
        }
        return 0;
}
