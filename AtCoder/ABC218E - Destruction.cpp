#include <bits/stdc++.h>

using namespace std;
using i64 = long long;
using ld = long double;

#define F first
#define S second

struct edge{
        int u , v , w;
        edge(){}
        edge(int u , int v , int w): u(u) , v(v) , w(w){}
        bool operator < (const edge &other){
                return w < other.w;
        }
};

int n , m;
vector < int > par , sz;
vector < edge > edges;

void make_set(int v){
        par[v] = v;
        sz[v] = 1;
}

int find_set(int v){
        return par[v] = par[v] == v ? v : find_set(par[v]);
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

int32_t main(){
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        cin >> n >> m;
        par.resize(n);
        sz.resize(n);
        for(int i = 0 ; i < n ; ++i){
                make_set(i);
        }
        while(m--){
                int u , v , w;
                cin >> u >> v >> w;
                u-- , v--;
                edges.emplace_back(u , v , w);
        }
        sort(edges.begin() , edges.end());
        i64 ans = 0;
        for(auto [u , v , w] : edges){
                if(find_set(u) != find_set(v)){
                        union_sets(u , v);
                }
                else{
                        ans += w > 0 ? w : 0;
                }
        }
        cout << ans;
        return 0;
}
