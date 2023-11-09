#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

int32_t main(){
        ios::sync_with_stdio(false);
        cin.tie(nullptr);

        int N;
        cin >> N;

        vector < array < i64 , 3 > > a(N - 1);
        for(int i = 0 ; i + 1 < N ; ++i){
                cin >> a[i][0] >> a[i][1] >> a[i][2];
        }

        for(int i = 0 ; i < N ; ++i){
                i64 ans = 0;
                for(int j = i ; j + 1 < N ; ++j){
                        i64 lo = -1 , hi = (i64) 1e9 + 5;
                        while(hi - lo > 1){
                                i64 mid = (lo + hi) / 2;
                                if(a[j][1] + mid * a[j][2] >= ans){
                                        hi = mid;
                                }else{
                                        lo = mid;
                                }
                        }
                        ans = a[j][1] + hi * a[j][2];
                        ans += a[j][0];
                }
                cout << ans << '\n';
        }

        return 0;
}
