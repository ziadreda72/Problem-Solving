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
        vector < vector < int > > v(m);
        for(int i = 0 ; i < m ; ++i){
                int k;
                cin >> k;
                while(k--){
                        int x;
                        cin >> x;
                        x--;
                        v[i].push_back(x);
                }
        }
        vector < int > p(m);
        for(int i = 0 ; i < m ; ++i)
                cin >> p[i];
        int ans = 0;
        for(int msk = 0 ; msk < (1 << n) ; ++msk){
                bool ok = 1;
                for(int i = 0 ; i < m ; ++i){
                        int t = 0;
                        for(auto x : v[i])
                              if(((msk >> x) & 1)) t ^= 1;
                        ok &= t == p[i];
                }
                ans += ok;
        }
        cout << ans;
        return 0;
}
