#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

#define F first
#define S second

struct point2d{
    i64 x , y;

    point2d(){}

    point2d(i64 x , i64 y): x(x) , y(y){}

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

i64 d(point2d a , point2d b){
    return ((a.x - b.x) * (a.x - b.x)) + ((a.y - b.y) * (a.y - b.y));
}

struct Edge{
    int u , v;
    i64 d;

    Edge(){}

    Edge(int u , int v , i64 d): u(u) , v(v) , d(d){}

    bool operator < (const Edge& other) const{
        return d > other.d;
    }
};

int s , n;
vector < int > par , sz;
int forest;

void make_set(int v){
    par[v] = v;
    sz[v] = 1;
}


void init(){
    par.resize(n);
    sz.resize(n);
    for (int i = 0; i < n; ++i) {
        make_set(i);
    }
    forest = n;
}

int find_set(int v){
    return par[v] = (par[v] == v ? v : find_set(par[v]));
}

void union_set(int a , int b){
    a = find_set(a);
    b = find_set(b);
    if(a != b){
        if(sz[a] < sz[b]) swap(a , b);
        sz[a] += sz[b];
        par[b] = a;
        forest--;
    }
}

void solve()
{
    cin >> s >> n;
    vector < point2d > a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i].x >> a[i].y;
    }
    priority_queue < Edge > pq;
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            pq.emplace(Edge(i , j , d(a[i] , a[j])));
        }
    }
    init();
    i64 mx = 0;
    while (!pq.empty() && forest > s){
        int u = pq.top().u , v = pq.top().v;
        i64 d = pq.top().d;
        pq.pop();
        if(find_set(u) != find_set(v)){
            mx = max(mx , d);
            union_set(u , v);
        }
    }
    cout << fixed << setprecision(2) << sqrt(mx);
}

int32_t main()
{
    ios::sync_with_stdio(false);cin.tie(nullptr);
    cout.tie(nullptr);
    int tc = 1;
    cin >> tc;
    while(tc--){
        solve();
        cout << '\n';
    }
    return 0;
}
