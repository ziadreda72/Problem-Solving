#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

struct DSU{
        int n , cmp;
        vector < int > par , sz;

        DSU(int n): n(n){}

        void init(){
                par.resize(n);
                sz.assign(n , 1);
                cmp = n;
                for(int i = 0 ; i < n ; ++i){
                        par[i] = i;
                }
        }

        int find_set(int v){
                return par[v] == v ? v : find_set(par[v]);
        }

        bool union_sets(int a , int b){
                a = find_set(a);
                b = find_set(b);

                if(a != b){
                        if(sz[a] < sz[b]){
                                swap(a , b);
                        }
                        
                        sz[a] += sz[b];
                        par[b] = a;
                        cmp--;
                        return true;
                }

                return false;
        }
};

int32_t main(){
        ios::sync_with_stdio(false);
        cin.tie(nullptr);

        int N , M;
        cin >> N >> M;

        DSU dsu(N);
        dsu.init();

        int ans = 0;

        while(M--){
                int u , v;
                char x , y;
                cin >> u >> x >> v >> y;

                ans += !dsu.union_sets(--u , --v);
        }

        cout << ans << ' ' << dsu.cmp - ans;

        return 0;
}
