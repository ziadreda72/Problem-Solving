#include <bits/stdc++.h>

using namespace std;
using i64 = long long;
using ld = long double;

const int MAX = (int) 1e5 + 5;

int n;
vector < int > g[MAX];
int deg[MAX];

bool is_leaf(int v){
        return v != 1 && deg[v] == 1;
}

ld dfs(int u , int par , ld p , int dep){
        if(is_leaf(u)){
                return (ld) 1.0 * p * dep;
        }
        ld ret = 0;
        for(auto v : g[u]){
                if(v == par) continue;
                ret += dfs(v , u , p / ((ld) deg[u] - 1) , dep + 1);
        }
        return ret;
}

int32_t main(){
        ios::sync_with_stdio(false);
        cin.tie(nullptr);

        cin >> n;

        for(int i = 0 ; i + 1 < n ; ++i){
                int u , v;
                cin >> u >> v;
                g[u].push_back(v);
                g[v].push_back(u);
                ++deg[u] , ++deg[v];
        }

        ld ans = 0.0;
        for(auto v : g[1]){
                ans += dfs(v , 1 , (ld) 1.0 / (ld) deg[1] , 1);
        }

        cout << fixed << setprecision(20) << ans;

        return 0;
}
