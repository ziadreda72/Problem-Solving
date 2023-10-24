#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

int32_t main(){
        ios::sync_with_stdio(false);
        cin.tie(nullptr);

        int N;
        cin >> N;

        vector < int > a(N) , cnt(N);
        for(int i = 0 ; i < N ; ++i){
                cin >> a[i];
                cnt[--a[i]]++;
        }

        i64 ans = 0;
        for(auto c : cnt){
                ans += 1LL * c * (c - 1) / 2;
        }

        for(int i = 0 ; i < N ; ++i){
                cout << ans - (cnt[a[i]] - 1) << '\n';
        }

        return 0;
}
