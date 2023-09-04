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
        vector < vector < int > > g(n);
        while(m--){
                int u , v;
                cin >> u >> v;
                u-- , v--;
                g[u].push_back(v);
        }
        int ans = 0;
        for(int i = 0 ; i < n ; ++i){
                vector < bool > vis(n , 0);
                queue < int > q;
                q.push(i);
                vis[i] = 1;
                int c = 0;
                while(!q.empty()){
                        c++;
                        int u = q.front();
                        q.pop();
                        for(auto v : g[u]){
                                if(!vis[v]){
                                        vis[v] = 1;
                                        q.push(v); 
                                }
                        }
                }
                ans += c;
        }
        cout << ans;
        return 0;
}
