#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

vector < int > par , sz;

void make_set(int v){
        par[v] = v;
        sz[v] = 1;
}

int find_set(int v){
        return par[v] == v ? v : find_set(par[v]);
}

void union_sets(int a , int b){
        a = find_set(a);
        b = find_set(b);
        if(a != b){
                if(sz[a] < sz[b])
                        swap(a , b);
                par[b] = a;
                sz[a] += sz[b];
        }
}

int32_t main() {
        ios::sync_with_stdio(false);cin.tie(nullptr);
        cout.tie(nullptr);cout.precision(20);
        int n , m;
        cin >> n >> m;
        if(m != n - 1){
                cout << "no";
                return 0;
        }
        par.resize(n);
        sz.resize(n);
        for (int i = 0; i < n; ++i) {
                make_set(i);
        }
        int cnt = 0;
        while (m--){
                int u , v;
                cin >> u >> v;
                u-- , v--;
                if(find_set(u) != find_set(v)){
                        union_sets(u , v);
                        cnt++;
                }
        }
        cout << (cnt == n - 1 ? "yes" : "no");
        return 0;
}
