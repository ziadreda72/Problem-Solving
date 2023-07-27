#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

struct point{
        int x , y;
        
        point(){}
        
        point(int x , int y): x(x) , y(y){}
};

int d(point a , point b){
        return ((a.x - b.x) * (a.x - b.x)) + ((a.y - b.y) * (a.y - b.y));
}

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
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        int n , D;
        cin >> n >> D;
        vector < point > a(n);
        par.resize(n);
        sz.resize(n);
        for (int i = 0; i < n; ++i) {
                cin >> a[i].x >> a[i].y;
                make_set(i);
        }
        for (int i = 0; i < n; ++i)
                for (int j = 0; j < n; ++j)
                        if(d(a[i] , a[j]) <= D * D)
                                union_sets(i , j);
        int root = find_set(0);
        for (int i = 0; i < n; ++i)
                cout << (find_set(i) == root ? "Yes\n" : "No\n");
        return 0;
}
