#include <bits/stdc++.h>

using namespace std;
using i64 = long long;
using ld = long double;

#define F first
#define S second

const int N = (int) 1e5 + 5;

int n , m;
vector < int > g[N];
bool vis[N];

void dfs(int u){
        vis[u] = 1;
        for(int v : g[u])
                if(!vis[v])
                        dfs(v);
}

int32_t main(){
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        cin >> n >> m;
        while(m--){
                int u , v;
                cin >> u >> v;
                g[u].push_back(v);
                g[v].push_back(u);
        }
        vector < int > components;
        for(int i = 1 ; i <= n ; ++i){
                if(!vis[i]){
                        components.push_back(i);
                        dfs(i);
                }
        }
        cout << (int) components.size() - 1 << '\n';
        for(int i = 0 ; i + 1 < components.size() ; ++i)
                cout << components[i] << ' ' << components[i + 1] << '\n';
        return 0;
}
