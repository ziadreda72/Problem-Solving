#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

struct DSU{
        int n;
        vector < int > par , sz;

        DSU(int n): n(n){}

        void init(){
                par.resize(n);
                iota(par.begin() , par.end() , 0);
                sz.assign(n , 1);
        }

        int get_ans(){
                int ret = 0;
                for(int i = 0 ; i < n ; ++i){
                        ret = max(ret , sz[par[i]]);
                }
                return ret;
        }

        int find_set(int v){
                return par[v] == v ? v : find_set(par[v]);
        }

        void union_sets(int a , int b){
                a = find_set(a);
                b = find_set(b);

                if(a != b){
                        if(sz[a] < sz[b]){
                                swap(a , b);
                        }
                        sz[a] += sz[b];
                        par[b] = a;
                }
        }
};

int32_t main(){
        ios::sync_with_stdio(false);
        cin.tie(nullptr);

        int N , M;
        cin >> N >> M;

        DSU dsu(N);
        dsu.init();

        while(M--){
                int A , B;
                cin >> A >> B;
                
                dsu.union_sets(--A , --B);
        }

        cout << dsu.get_ans();

        return 0;
}
