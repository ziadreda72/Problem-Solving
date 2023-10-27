#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

int32_t main(){
        ios::sync_with_stdio(false);
        cin.tie(nullptr);

        const int MOD = (int) 1e9 + 7;

        int N;
        cin >> N;

        vector < int > cnt(N);
        for(int i = 0 ; i < N ; ++i){
                int x;
                cin >> x;

                ++cnt[x];
        }

        bool ok = N & 1 ? cnt[0] == 1 : cnt[0] == 0;
        for(int i = N - 1 ; i > 0 ; i -= 2){
                ok &= cnt[i] == 2;
        }

        if(ok){
                int ans = 1;
                for(int i = 0 ; i < N / 2 ; ++i){
                        ans *= 2;
                        ans %= MOD;
                }
                cout << ans;
        }else cout << 0;

        return 0;
}
