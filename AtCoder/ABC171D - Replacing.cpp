#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

int32_t main(){
        ios::sync_with_stdio(false);
        cin.tie(nullptr);

        const int MAX = (int) 1e5 + 5;

        int N;
        cin >> N;

        vector < i64 > cnt(MAX , 0LL);

        i64 ans = 0;

        for(int i = 0 ; i < N ; ++i){
                i64 x;
                cin >> x;
                ++cnt[x];
                ans += x;
        }

        int Q;
        cin >> Q;

        while(Q--){
                i64 b , c;
                cin >> b >> c;
                
                ans += cnt[b] * (c - b);

                cnt[c] += cnt[b];
                cnt[b] = 0;

                cout << ans << '\n';
        }

        return 0;
}
