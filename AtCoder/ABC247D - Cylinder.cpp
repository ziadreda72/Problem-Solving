#include <bits/stdc++.h>

using namespace std;
using i64 = long long;
using ld = long double;

#define F first
#define S second

int32_t main(){
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        int Q;
        cin >> Q;
        deque < array < int , 2 > > d;
        while(Q--){
                int t;
                cin >> t;
                if(t == 1){
                        array < int , 2 > a{};
                        cin >> a[0] >> a[1];
                        d.push_back(a);
                }
                else{
                        int c;
                        cin >> c;
                        i64 ans = 0;
                        while(c){
                                auto x = d.front();
                                d.pop_front();
                                auto mn = min(c , x[1]);
                                ans += 1LL * x[0] * mn;
                                c -= mn;
                                x[1] -= mn;
                                if(x[1])
                                        d.push_front(x);
                        }
                        cout << ans << '\n';
                }
        }
        return 0;
}
