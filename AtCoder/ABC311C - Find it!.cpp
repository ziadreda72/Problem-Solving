#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

const int N = (int) 2e5 + 5;

int n;
vector < int > g[N];
vector < int > color(N , 0) , par(N , -1);
int st , en;

bool dfs(int u){
        color[u] = 1;
        for(auto v : g[u]){
                if(color[v] == 0){
                        par[v] = u;
                        if(dfs(v))
                                return true;
                }else if(color[v] == 1){
                        st = v;
                        en = u;
                        return true;
                }
        }
        color[u] = 2;
        return false;
}

int32_t main() {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        cin >> n;
        for (int i = 1; i <= n; ++i) {
                int x;
                cin >> x;
                g[i].push_back(x);
        }
        for (int i = 1; i <= n; ++i) {
                if(color[i] == 0 && dfs(i))
                        break;
        }
        vector < int > ans;
        for (int v = en;; v = par[v]) {
                ans.push_back(v);
                if(v == st)
                        break;
        }
        cout << ans.size() << '\n';
        reverse(ans.begin(), ans.end());
        for(auto x : ans)
                cout << x << ' ';
        return 0;
}
