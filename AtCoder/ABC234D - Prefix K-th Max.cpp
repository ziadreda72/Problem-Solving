#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace __gnu_pbds; 
  
#define ordered_set tree < int , null_type , less < int > , rb_tree_tag , tree_order_statistics_node_update >

int32_t main(){
        ios::sync_with_stdio(false);
        cin.tie(nullptr);

        int N , K;
        cin >> N >> K;

        vector < int > a(N);
        for(int i = 0 ; i < N ; ++i) cin >> a[i];

        ordered_set s;
        for(int i = 0 ; i + 1 < K ; ++i) s.insert(a[i]);

        for(int i = K - 1 ; i < N ; ++i){
                s.insert(a[i]);
                int sz = (int) s.size();
                cout << *(s.find_by_order(sz - K)) << '\n';
        }

        return 0;
}
