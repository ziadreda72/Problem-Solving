#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

int32_t main(){
        ios::sync_with_stdio(false);
        cin.tie(nullptr);

        int N , M , Q;
        cin >> N >> M >> Q;

        vector < array < int , 2 > > a(N);
        for(int i = 0 ; i < N ; ++i){
                cin >> a[i][0] >> a[i][1];
                swap(a[i][0] , a[i][1]);
        }

        sort(a.rbegin() , a.rend());

        vector < int > b(M);
        for(int i = 0 ; i < M ; ++i){
                cin >> b[i];
        }

        while(Q--){
                int L , R;
                cin >> L >> R;
                --L , --R;
                
                multiset < int > st;
                for(int i = 0 ; i < M ; ++i){
                        if(L <= i && i <= R) continue;
                        st.insert(b[i]);
                }

                int ans = 0;
                for(auto [v , w] : a){
                        auto it = st.lower_bound(w);
                        if(it != st.end()){
                                ans += v;
                                st.erase(it);
                        }
                }

                cout << ans << '\n';
        }

        return 0;
}
