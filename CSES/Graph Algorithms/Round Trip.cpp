
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
int parent[N] , st , en;
 
bool dfs(int u , int par){
        vis[u] = 1;
        for(int v : g[u]){
                if(v == par)
                        continue;
                if(vis[v]){
                        st = v;
                        en = u;
                        return true;
                }
                parent[v] = u;
                if(dfs(v , u))
                        return true;
        }
        return false;
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
        st = -1;
        for(int i = 1 ; i <= n ; ++i){
                if(!vis[i] && dfs(i , -1))
                        break;
 
        }
        if(st == -1){
                cout << "IMPOSSIBLE";
        }
        else{
                vector < int > ans;
                ans.push_back(st);
                for(int v = en ; v != st ; v = parent[v])
                        ans.push_back(v);
                ans.push_back(st);
                reverse(ans.begin() , ans.end());
                cout << ans.size() << '\n';
                for(auto x : ans)
                        cout << x << ' ';
        }
        return 0;
}
