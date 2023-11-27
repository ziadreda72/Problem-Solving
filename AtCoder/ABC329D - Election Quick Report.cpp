#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

int32_t main(){
        ios::sync_with_stdio(false);
        cin.tie(nullptr);

        int N , M;
        cin >> N >> M;

        vector < int > cnt(N + 1 , 0);

        int ans = 0 , mx = 0;
        while(M--){
                int x;
                cin >> x;

                ++cnt[x];

                if(cnt[x] == mx){
                        ans = min(ans , x);
                }

                if(cnt[x] > mx){
                        ans = x;
                        mx = cnt[x];
                }

                cout << ans << '\n';
        } 

        return 0;
}
