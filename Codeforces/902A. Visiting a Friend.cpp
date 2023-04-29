#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

#define F first
#define S second

int n , m;
vector < int > par , sz;

void make_set(int v){
    par[v] = v;
    sz[v] = 1;
}

int find_set(int v){
    return par[v] = (par[v] == v ? v : find_set(par[v]));
}

void union_sets(int a , int b){
    a = find_set(a) , b = find_set(b);
    if(a != b){
        if(sz[a] < sz[b]) swap(a , b);
        par[b] = a;
        sz[a] += sz[b];
    }
}

int32_t main() {
    ios::sync_with_stdio(false);cin.tie(nullptr);
    cout.tie(nullptr);cout.precision(20);
    cin >> n >> m;
    par.resize(m + 1);
    sz.resize(m + 1);
    for (int i = 0; i <= m; ++i) {
        make_set(i);
    }
    for (int i = 0; i < n; ++i) {
        int a , b;
        cin >> a >> b;
        for (int j = a; j <= b; ++j) {
            if(find_set(a) != find_set(j)) union_sets(a , j);
        }
    }
    cout << (find_set(0) == find_set(m) ? "YES" : "NO");
    return 0;
}
