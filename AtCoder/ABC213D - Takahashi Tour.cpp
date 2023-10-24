#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

const int MAX = 2E5 + 5;

int N;
vector < int > g[MAX];

void dfs(int u , int par = 0){
        cout << u << ' ';

        for(auto v : g[u]){
                if(v == par) continue;
                dfs(v , u);
        }

        if(par){
                cout << par << ' ';
        }
}

int32_t main(){
        ios::sync_with_stdio(false);
        cin.tie(nullptr);

        cin >> N;

        for(int i = 0 ; i + 1 < N ; ++i){
                int u , v;
                cin >> u >> v;

                g[u].push_back(v);
                g[v].push_back(u);
        }

        for(int i = 1 ; i <= N ; ++i) sort(g[i].begin() , g[i].end());

        dfs(1);

        return 0;
}
