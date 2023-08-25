#include <bits/stdc++.h>

using namespace std;
using i64 = long long;
using ld = long double;

#define F first
#define S second

int32_t main(){
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        int n , m;
        cin >> n >> m;
        vector < pair < int , int > > v(m);
        for(int i = 0 ; i < m ; ++i)
                cin >> v[i].F >> v[i].S;
        int k;
        cin >> k;
        vector < array < int , 2 > > v2(k);
        for(int i = 0 ; i < k ; ++i)
                cin >> v2[i][0] >> v2[i][1];
        int ans = 0;
        for(int msk = 0 ; msk < (1 << k) ; ++msk){
                set < int > st;
                for(int i = 0 ; i < k ; ++i)
                        st.insert(v2[i][(msk >> i) & 1]);
                int cnt = 0;
                for(auto [x , y] : v)
                        cnt += (st.find(x) != st.end()) && (st.find(y) != st.end());
                ans = max(ans , cnt);
        }
        cout << ans;
        return 0;
}
