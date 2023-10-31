#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

struct DSU{
        int N , cmp;
        vector < int > par , sz;

        DSU(int N){
                this->N = N;
                cmp = N;
                par.resize(N);
                iota(par.begin() , par.end() , 0);
                sz.assign(N , 1);
        }

        int find_set(int v){
                return par[v] = (par[v] == v ? v : find_set(par[v]));
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
                        cmp--;
                }
        }
        
};

int32_t main(){
        ios::sync_with_stdio(false);
        cin.tie(nullptr);

        int N , M;
        cin >> N >> M;

        vector < array < int , 2 > > E(M);
        for(int i = 0 ; i < M ; ++i){
                cin >> E[i][0] >> E[i][1];
        }

        int ans = 0;
        for(int i = 0 ; i < M ; ++i){
                DSU dsu(N);
                for(int j = 0 ; j < M ; ++j){
                        if(i == j) continue;
                        dsu.union_sets(E[j][0] - 1 , E[j][1] - 1);
                }
                ans += dsu.cmp > 1;
        }

        cout << ans;

        return 0;
}
