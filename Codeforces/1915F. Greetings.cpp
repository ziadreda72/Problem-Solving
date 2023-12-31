#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

#include <iostream>
#include <vector>

using namespace std;

#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace __gnu_pbds; 
  
#define ordered_set tree < int , null_type , less < int > , rb_tree_tag , tree_order_statistics_node_update >

void solveTC(){
        int n;
        cin >> n;

        vector < pair < int , int > > v(n);
        for (int i = 0 ; i < n ; ++i) {
                cin >> v[i].first >> v[i].second;
        }

        sort(v.begin() , v.end() , [](pair < int , int > a , pair < int , int > b){
                return a.second < b.second;
        });

        ordered_set st;

        i64 ans = 0;
        for (int i = 0 ; i < n ; ++i) {
                ans += st.size() - st.order_of_key(v[i].first);
                st.insert(v[i].first);
        }

        cout << ans;
}

int32_t main(){
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        
        int tc;
        cin >> tc;
        
        while (tc--){
                solveTC();
                cout << '\n';
        }
        
        return 0;
}
