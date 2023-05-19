#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

#define F first
#define S second

const int inf = (int) 1e7;

void solveTC() {
    int n , k;
    cin >> n >> k;
    vector < int > a(k);
    for (int i = 0; i < k; ++i) {
        cin >> a[i];
        a[i]--;
    }
    vector < vector < int > > g(n);
    vector < int > d(n , inf) , d2(n , inf) , deg(n , 0);
    for (int i = 0; i < n - 1; ++i) {
        int u , v;
        cin >> u >> v;
        u-- , v--;
        g[u].push_back(v);
        g[v].push_back(u);
        deg[u]++ , deg[v]++;
    }
    vector < int > leaf;
    for (int i = 1; i < n; ++i) {
        if(deg[i] == 1)
            leaf.push_back(i);
    }
    queue < int > q;
    q.push(0);
    d[0] = 0;
    while (!q.empty()){
        int u = q.front();
        q.pop();
        for(auto v : g[u]){
            if(d[u] + 1 < d[v]){
                d[v] = d[u] + 1;
                q.push(v);
            }
        }
    }
    for(auto x : a){
        q.push(x);
        d2[x] = 0;
    }
    while (!q.empty()){
        int u = q.front();
        q.pop();
        for(auto v : g[u]){
            if(d2[u] + 1 < d2[v]){
                d2[v] = d2[u] + 1;
                q.push(v);
            }
        }
    }
    for(auto l : leaf){
        if(d[l] < d2[l]){
            cout << "YES";
            return;
        }
    }
    cout << "NO";
}

int32_t main() {
    ios::sync_with_stdio(false);cin.tie(nullptr);
    cout.tie(nullptr);cout.precision(20);
    int tc = 1;
    cin >> tc;
    while(tc--){
        solveTC();
        cout << '\n';
    }
    return 0;
}
