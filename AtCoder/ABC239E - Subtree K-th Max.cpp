#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

const int MAX = (int) 1e5 + 5 , K = 20;

int N , Q;
int a[MAX];
vector < int > g[MAX] , mx[MAX];

void dfs(int u , int par){
        mx[u].push_back(a[u]);

        for(auto v : g[u]){
                if(v == par) continue;
                dfs(v , u);
        }

        if(par == 0) return;

        for(auto x : mx[u]){
                if(mx[par].size() < K){
                        mx[par].push_back(x);
                        sort(mx[par].rbegin() , mx[par].rend());
                }else{
                        if(x > mx[par].back()){
                                mx[par].pop_back();
                                mx[par].push_back(x);
                                sort(mx[par].rbegin() , mx[par].rend());
                        }
                }
        }
}

int32_t main(){
        ios::sync_with_stdio(false);
        cin.tie(nullptr);

        cin >> N >> Q;

        for(int i = 1 ; i <= N ; ++i) cin >> a[i];

        for(int i = 0 ; i + 1 < N ; ++i){
                int u , v;
                cin >> u >> v;

                g[u].push_back(v);
                g[v].push_back(u);
        }

        dfs(1 , 0);

        while(Q--){
                int v , k;
                cin >> v >> k;

                cout << mx[v][k - 1] << '\n';
        }

        return 0;
}
