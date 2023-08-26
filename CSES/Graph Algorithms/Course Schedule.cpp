#include <bits/stdc++.h>

using namespace std;
using i64 = long long;
using ld = long double;

#define F first
#define S second

const int N = (int) 1e5 + 5;

int n , m;
vector < int > g[N];
int color[N];
stack < int > ans;

bool dfs(int u){
        color[u] = 1;
        for(int v : g[u]){
                if((color[v] == 0 && dfs(v)) || color[v] == 1)
                        return true;
        }
        color[u] = 2;
        ans.push(u);
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
        for(int i = 1 ; i <= n ; ++i){
                if(color[i] == 0 && dfs(i)){
                        cout << "IMPOSSIBLE";
                        return 0;
                }
        }
        while(!ans.empty()){
                cout << ans.top() << ' ';
                ans.pop();
        }
        return 0;
}
