#include <bits/stdc++.h>

using namespace std;
using i64 = long long;
using ld = long double;

set < i64 > st;

void build(i64 x) {
        if(x <= (i64) 1e9){
                st.insert(x);
        }else{
                return;
        }

        build(x * 10 + 4);
        build(x * 10 + 7);
}

i64 calc(i64 l , i64 r , i64 l2 , i64 r2) {
        return max(0LL , min(r , r2) - max(l , l2) + 1);
}

int32_t main(){
        ios::sync_with_stdio(false);
        cin.tie(nullptr);

        build(0);
        st.insert((i64) 1e10);
        
        vector < i64 > p(2) , v(2);
        cin >> p[0] >> p[1] >> v[0] >> v[1];
 
        int k;
        cin >> k; 

        vector < i64 > a(st.begin() , st.end());

        int n = (int) a.size();

        i64 x = 0;

        for(int i = 1 ; i + k < n ; ++i){
                int j = i + k - 1;
                x += 1LL * calc(a[i - 1] + 1 , a[i] , p[0] , p[1]) * calc(a[j] , a[j + 1] - 1 , v[0] , v[1]);
                x += 1LL * calc(a[i - 1] + 1 , a[i] , v[0] , v[1]) * calc(a[j] , a[j + 1] - 1 , p[0] , p[1]);
                if(k == 1){
                        x -= calc(a[i] , a[i] , p[0] , p[1]) && calc(a[i] , a[i] , v[0] , v[1]);
                }
        }

        ld y = ((ld) (p[1] - p[0] + 1) * (ld) (v[1] - v[0] + 1));

        ld ans = (ld) x / y;

        cout << fixed << setprecision(20) << ans;

        return 0;
}
