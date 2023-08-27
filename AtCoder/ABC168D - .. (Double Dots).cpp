#include <bits/stdc++.h>

using namespace std;
using i64 = long long;
using ld = long double;

#define F first
#define S second

int32_t main(){
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        int n , m;
        cin >> n >> m;
        vector < vector < int > > g(n + 1);
        while(m--){
                int u , v;
                cin >> u >> v;
                g[u].push_back(v);
                g[v].push_back(u);
        }
        vector < bool > vis(n + 1 , 0);
        vector < int > par(n + 1 , -1);
        queue < int > q;
        q.push(1);
        vis[1] = 1;
        while(!q.empty()){
                int u = q.front();
                q.pop();
                for(int v : g[u]){
                        if(vis[v])
                                continue;
                        par[v] = u;
                        vis[v] = 1;
                        q.push(v);
                }
        }
        bool ans = 1;
        for(int i = 1 ; i <= n ; ++i)
                ans &= vis[i];
        if(!ans){
                cout << "No";
                return 0;
        }
        cout << "Yes\n";
        for(int i = 2 ; i <= n ; ++i)
                cout << par[i] << '\n';
        return 0;
}
