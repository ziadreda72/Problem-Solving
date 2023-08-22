#include <bits/stdc++.h>

using namespace std;
using i64 = long long;
using i128 = __int128;
using ld = long double;

#define F first
#define S second

int n , m;
vector < int > par , sz;
int cmp;

void make_set(int v){
        par[v] = v;
        sz[v] = 1;
        cmp++;
}

int find_set(int v){
        return par[v] = (v == par[v] ? v : find_set(par[v]));
}

void union_sets(int a , int b){
        a = find_set(a);
        b = find_set(b);
        if(a != b){
                if(sz[a] < sz[b])
                        swap(a , b);
                sz[a] += sz[b];
                par[b] = a;
                cmp--;
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
                int u , v;
                cin >> u >> v;
                u-- , v--;
                union_sets(u , v);
        }
        cout << cmp - 1;
        return 0;
}
