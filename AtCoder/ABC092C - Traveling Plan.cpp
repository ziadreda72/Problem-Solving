#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

int32_t main(){
        ios::sync_with_stdio(false);
        cin.tie(nullptr);

        int N;
        cin >> N;

        vector < int > a(N + 2 , 0);
        for(int i = 1 ; i <= N ; ++i){
                cin >> a[i];
        }

        int ans = 0;
        for(int i = 0 ; i <= N ; ++i){
                ans += abs(a[i] - a[i + 1]);
        }

        for(int i = 1 ; i <= N ; ++i){
                cout << ans - abs(a[i - 1] - a[i]) - abs(a[i] - a[i + 1]) + abs(a[i - 1] - a[i + 1]) << '\n';
        }

        return 0;
}
