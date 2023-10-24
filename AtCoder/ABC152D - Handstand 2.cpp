#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

int32_t main(){
        ios::sync_with_stdio(false);
        cin.tie(nullptr);

        int N;
        cin >> N;

        map < array < char , 2 > , i64 > mp;
        for(int i = 1 ; i <= N ; ++i){
                string s = to_string(i);
                mp[{s[0] , s.back()}]++;
        }

        i64 ans = 0;
        for(auto [p , x] : mp){
                ans += 1LL * x * (mp[{p[1] , p[0]}]);
        }

        cout << ans;

        return 0;
}
