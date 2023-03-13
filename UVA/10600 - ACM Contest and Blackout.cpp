#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

#define F first
#define S second

struct edge{
    int u , v , w;

    edge() {}

    edge(int u , int v , int w): u(u) , v(v) , w(w){}

    bool operator < (const edge& other){
        return w < other.w;
    }

    bool operator == (const edge& other) const{
        return u == other.u && v == other.v && w == other.w;
    }
};

vector < int > par , sz;

void make_set(int v){
    par[v] = v;
    sz[v] = 1;
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
    }
}

int n , m;
vector < edge > a;

edge ex;

int second_MST(){
    a.clear();
    par.resize(n);
    sz.resize(n);
    for (int i = 0; i < n; ++i) {
        make_set(i);
    }
    int ret = 0;
    for (int i = 0; i < m; ++i) {
        if(a[i] == ex) continue;
        int u = a[i].u , v = a[i].v , w = a[i].w;
        if(find_set(u) != find_set(v)){
            ret += w;
            union_sets(u , v);
        }
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if(find_set(i) != find_set(j)) return INT32_MAX;
        }
    }
    return ret;
}

void solve()
{
    cin >> n >> m;
    par.resize(n);
    sz.resize(n);
    for (int i = 0; i < n; ++i) {
        make_set(i);
    }
    for (int i = 0; i < m; ++i) {
        int u , v , w;
        cin >> u >> v >> w;
        u-- , v--;
        a.emplace_back(edge(u , v , w));
    }
    sort(a.begin(), a.end());
    int mn = 0;
    vector < edge > MST;
    for (int i = 0; i < m; ++i) {
        int u = a[i].u , v = a[i].v , w = a[i].w;
        if(find_set(u) != find_set(v)){
            mn += w;
            union_sets(u , v);
            MST.emplace_back(a[i]);
        }
    }
    cout << mn << ' ';
    mn = INT32_MAX;
    for(auto e : MST){
        ex = e;
        mn = min(mn , second_MST());
    }
    cout << mn;
}

int32_t main()
{
    ios::sync_with_stdio(false);cin.tie(nullptr);
    cout.tie(nullptr);cout.precision(20);
    int tc = 1;
    cin >> tc;
    while(tc--){
        solve();
        cout << '\n';
    }
    return 0;
}
