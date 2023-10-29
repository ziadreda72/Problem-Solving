#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

int32_t main(){
        ios::sync_with_stdio(false);
        cin.tie(nullptr);

        int N , T;
        cin >> N >> T;

        vector < array < i64 , 2 > > a(N);
        for(int i = 0 ; i < N ; ++i){
                cin >> a[i][0];
                a[i][1] = a[i][0] + T;
        }

        i64 ans = 0;
        for(int i = 0 ; i < N ; ++i){
                if(i + 1 < N && a[i + 1][0] < a[i][1]){
                        ans += a[i + 1][0] - a[i][0];
                }else{
                        ans += T;
                }
        }

        cout << ans;

        return 0;
}
