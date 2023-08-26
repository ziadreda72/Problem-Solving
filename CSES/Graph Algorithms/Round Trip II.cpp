
#include <bits/stdc++.h>
 
using namespace std;
using i64 = long long;
using ld = long double;
 
#define F first
#define S second
 
const int N = (int) 1e5 + 5;
 
int n , m;
vector < int > g[N];
int color[N] , par[N] , st , en;
 
bool dfs(int u){
        color[u] = 1;
        for(int v : g[u]){
                if(color[v] == 0){
                        par[v] = u;
                        if(dfs(v))
                                return true;
                }
                else if(color[v] == 1){
                        st = v;
                        en = u;
                        return true;
                }
        }
        color[u] = 2;
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
        }
        st = -1;
        for(int i = 1 ; i <= n ; ++i){
                if(color[i] == 0 && dfs(i))
                        break;
        }
        if(st == -1){
                cout << "IMPOSSIBLE";
                return 0;
        }
        vector < int > ans;
        ans.push_back(st);
        for(int v = en ; v != st ; v = par[v])
                ans.push_back(v);
        ans.push_back(st);
        reverse(ans.begin() , ans.end());
        cout << ans.size() << '\n';
        for(auto x : ans)
                cout << x << ' ';
        return 0;
}
