#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

#define F first
#define S second

const int OO = INT_MAX;

int n , m;
vector < vector < pair < int , int > > > g;
vector < int > d;
vector < bool > vis;
deque < int > q;

int32_t main() {
    ios::sync_with_stdio(false);cin.tie(nullptr);
    cout.tie(nullptr);cout.precision(20);
    cin >> n >> m;
    g = vector < vector < pair < int , int > > > (n);
    d = vector < int > (n , OO);
    vis = vector < bool > (n , 0);
    while (m--){
        int u , v , w;
        cin >> u >> v >> w;
        u-- , v--;
        g[u].push_back({v , w});
        g[v].push_back({u , w});
    }
    q.push_back(0);
    d[0] = 0;
    while (!q.empty()){
        int u = q.front();
        q.pop_front();
        if(vis[u])
            continue;
        vis[u] = 1;
        for(auto e : g[u]){
            int v = e.F;
            int w = e.S;
            if(d[u] + w < d[v]){
                d[v] = d[u] + w;
                w ? q.push_back(v) : q.push_front(v);
            }
        }
    }
    /*
    5 6
    1 2 0
    1 5 1
    2 5 1
    2 3 0
    2 4 1
    3 4 0
    Output should be:
    0 0 0 0 1
    */
    for (int i = 0; i < n; ++i) {
        cout << d[i] << ' ';
    }
    return 0;
}
