#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

int32_t main(){
        ios::sync_with_stdio(false);
        cin.tie(nullptr);

        int N , A , B;
        cin >> N >> A >> B;

        string s;
        cin >> s;

        i64 ans = INT64_MAX;
        for(int i = 0 ; i < N ; ++i){
                i64 x = 1LL * i * A;
                for(int j = 0 ; j * 2 < N ; ++j) x += (s[j] != s[N - j - 1]) * B;
                rotate(s.begin() , s.begin() + 1 , s.end());
                ans = min(ans , x);
        }

        cout << ans;

        return 0;
}
