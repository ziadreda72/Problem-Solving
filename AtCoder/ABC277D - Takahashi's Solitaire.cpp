#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

int32_t main(){
        ios::sync_with_stdio(false);
        cin.tie(nullptr);

        int N , M;
        cin >> N >> M;

        vector < int > a(N);
        multiset < int > s;
        i64 sum = 0;
        for(int i = 0 ; i < N ; ++i){
                cin >> a[i];
                s.insert(a[i]);
                sum += a[i];
        }

        i64 ans = sum;
        auto check = [&](int x){
                i64 t = sum;
                while(s.count(x) && t){
                        t -= 1LL * x * s.count(x);
                        x = (x + 1) % M;
                }
                ans = min(ans , t);
        };

        sort(a.begin() , a.end());

        check(a[0]);
        for(int i = 1 ; i < N ; ++i){
                if(a[i] - a[i - 1] > 1){
                        check(a[i]);
                }
        }

        cout << ans;

        return 0;
}
