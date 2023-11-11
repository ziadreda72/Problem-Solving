#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

const i64 INF = (i64) 1e17; 

struct edge{
        int u , v;
        i64 w;

        edge(){}

        edge(int u , int v , i64 w): u(u) , v(v) , w(w){}
};

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
                        cmp--;
                        sz[a] += sz[b];
                        par[b] = a;
                }
        }
};

int N , M;
i64 K;
vector < edge > E , sub;
i64 ans = INF;

void solve(int i , int c){
        if(c == N - 1){
                DSU dsu(N);
                i64 tot = 0;
                for(auto [u , v , w] : sub){
                        tot = (tot + w) % K;
                        dsu.union_sets(u , v);
                }
                if(dsu.cmp == 1){
                        ans = min(ans , tot);
                }
                return;
        }

        if(i >= M) return;

        sub.push_back(E[i]);
        solve(i + 1 , c + 1);
        sub.pop_back();

        solve(i + 1 , c);
}

int32_t main(){
        ios::sync_with_stdio(false);
        cin.tie(nullptr);

        cin >> N >> M >> K;

        for(int i = 0 ; i < M ; ++i){
                int u , v;
                i64 w;
                cin >> u >> v >> w;
                E.push_back({--u , --v , w});
        }

        solve(0 , 0);

        cout << ans;

        return 0;
}
