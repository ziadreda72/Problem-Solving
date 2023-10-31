#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

int32_t main(){
        ios::sync_with_stdio(false);
        cin.tie(nullptr);

        int N;
        cin >> N;

        vector < int > a(N);
        for(int i = 0 ; i < N ; ++i){
                cin >> a[i];
                --a[i];
        }

        int ans = 0;
        for(int i = 0 ; i + 1 < N ; ++i){
                if(a[i] == i){
                        swap(a[i] , a[i + 1]);
                        ans++;
                }
        }

        ans += a[N - 1] == (N - 1);

        cout << ans;

        return 0;
}
