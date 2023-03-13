#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

#define F first
#define S second

struct Edge{
    int i , j , d;
    
    Edge(int i , int j , int d): i(i) , j(j) , d(d){}

    bool operator < (const Edge& other){
        if(d == other.d){
            if(i == other.i) return j <= other.j;
            return i < other.i;
        }
        return d < other.d;
    }
};

struct point2d{
    int x , y;

    point2d(){}

    point2d(int x , int y): x(x) , y(y){}

    point2d& operator += (const point2d &t){
        x += t.x;
        y += t.y;
        return *this;
    }

    point2d& operator -= (const point2d &t){
        x -= t.x;
        y -= t.y;
        return *this;
    }

    point2d& operator *= (int t){
        x *= t;
        y *= t;
        return *this;
    }

    point2d& operator /= (int t){
        x /= t;
        y /= t;
        return *this;
    }

    point2d operator + (const point2d &t) const{
        return point2d(*this) += t;
    }

    point2d operator - (const point2d &t) const{
        return point2d(*this) -= t;
    }

    point2d operator * (int t) const{
        return point2d(*this) *= t;
    }

    point2d operator / (int t) const{
        return point2d(*this) /= t;
    }
};

int dis(point2d a , point2d b){
    return ((a.x - b.x) * (a.x - b.x)) + ((a.y - b.y) * (a.y - b.y));
}

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
        if(sz[a] < sz[b]) swap(a , b);
        sz[a] += sz[b];
        par[b] = a;
    }
}

void solve()
{
    int n;
    cin >> n;
    par.resize(n + 1);
    sz.resize(n + 1);
    for (int i = 1; i <= n ; ++i) {
        make_set(i);
    }
    vector < point2d > a(n + 1);
    for (int i = 1; i <= n; ++i) {
        int x , y;
        cin >> x >> y;
        a[i] = point2d(x , y);
    }
    int m;
    cin >> m;
    while (m--){
        int i , j;
        cin >> i >> j;
        union_sets(i , j);
    }
    vector < Edge > edge_list;
    for (int i = 1; i <= n ; ++i) {
        for (int j = i + 1; j <= n; ++j) {
            if(find_set(i) != find_set(j)){
                edge_list.emplace_back(i , j , dis(a[i] , a[j]));
            }
        }
    }
    sort(edge_list.begin(), edge_list.end());
    vector < pair < int , int > > ans;
    for (int i = 0; i < (int) edge_list.size(); ++i) {
        int x = edge_list[i].i , y = edge_list[i].j;
        if (find_set(x) != find_set(y)){
            ans.emplace_back(x , y);
            union_sets(x , y);
        }
    }
    if(ans.empty()){
        cout << "No new highways need\n";
        return;
    }
    for(auto [i , j] : ans) cout << i << ' ' << j << '\n';
}

int32_t main()
{
    ios::sync_with_stdio(false);cin.tie(nullptr);
    cout.tie(nullptr);cout.precision(20);
    int tc = 1;
    cin >> tc;
    for (int i = 1; i <= tc; ++i) {
        solve();
        if(i == tc) continue;
        cout << '\n';
    }
    return 0;
}
