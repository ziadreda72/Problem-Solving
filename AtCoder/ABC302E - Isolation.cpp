#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

int32_t main(){
        ios::sync_with_stdio(false);
        cin.tie(nullptr);

        int n , q;
        cin >> n >> q;

        vector < set < int > > g(n);
        vector < int > deg(n);

        int ans = n;
        while(q--){
                int t;
                cin >> t;

                if(t == 1){
                        int u , v;
                        cin >> u >> v;
                        ans -= (!deg[--u]++) + (!deg[--v]++);
                        g[u].insert(v);
                        g[v].insert(u);
                }else{
                        int u;
                        cin >> u;
                        ans += deg[--u] > 0;
                        deg[u] = 0;
                        for(auto v : g[u]){
                                g[v].erase(u);
                                ans += !--deg[v];
                        }
                        g[u].clear();
                }
                
                cout << ans << '\n';
        }

        return 0;
}
