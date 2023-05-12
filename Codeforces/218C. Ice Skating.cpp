#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

#define F first
#define S second

int n;
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
        if(sz[a] < sz[b])
            swap(a , b);
        sz[a] += sz[b];
        par[b] = a;
    }
}

int32_t main() {
    ios::sync_with_stdio(false);cin.tie(nullptr);
    cout.tie(nullptr);cout.precision(20);
    cin >> n;
    par.resize(n);
    sz.resize(n);
    for (int i = 0; i < n; ++i) {
        make_set(i);
    }
    map < int , vector < int > > mp , mp2;
    for (int i = 0; i < n; ++i) {
        int x , y;
        cin >> x >> y;
        mp[x].push_back(i);
        mp2[y].push_back(i);
    }
    for(auto [x , v] : mp){
        int p = v[0];
        for (int i = 1; i < (int) v.size(); ++i) {
            if(find_set(p) != find_set(v[i]))
                union_sets(p , v[i]);
        }
    }
    for(auto [y , v] : mp2){
        int p = v[0];
        for (int i = 1; i < (int) v.size(); ++i) {
            if(find_set(p) != find_set(v[i]))
                union_sets(p , v[i]);
        }
    }
    set < int > st;
    for (int i = 0; i < n; ++i) {
        st.insert(find_set(i));
    }
    cout << (int) st.size() - 1;
    return 0;
}
