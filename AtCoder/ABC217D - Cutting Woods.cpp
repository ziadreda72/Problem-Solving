#include <bits/stdc++.h>

using namespace std;
using i64 = long long;
using ld = long double;

#define F first
#define S second

int32_t main(){
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        int l , q;
        cin >> l >> q;
        set < pair < int , int > > st;
        st.insert({0 , l});
        while(q--){
                int t;
                cin >> t;
                int x;
                cin >> x;
                auto it = st.lower_bound({x, std::numeric_limits<int>::min()});
                it--;
                auto p = *it;
                if(t == 1){
                        st.erase(it);
                        pair < int , int > p2 = {p.F , x} , p3 = {x , p.S};
                        st.insert(p2);
                        st.insert(p3);
                }
                else{
                        cout << p.S - p.F << '\n';
                }
        }
        return 0;
}
