#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

bool dfs(vector < vector < int > > &g , vector < bool > &vis , int u , int par){
        vis[u] = 1;
        for(auto v : g[u]){
                if(v == par) continue;
                if(vis[v]){
                        return true;
                }else{
                        if(dfs(g , vis , v , u)){
                                return true;
                        }
                }
        }
        return false;
}

int32_t main(){
        ios::sync_with_stdio(false);
        cin.tie(nullptr);

        int N , M;
        cin >> N >> M;

        vector < int > deg(N , 0);
        
        vector < vector < int > > g(N);

        while(M--){
                int a , b;
                cin >> a >> b;

                deg[--a]++ , deg[--b]++;
                
                g[a].push_back(b);
                g[b].push_back(a);
        }

        bool ans = 1;
        for(int i = 0 ; i < N ; ++i){
                ans &= deg[i] <= 2;
        }

        vector < bool > vis(N , 0);

        for(int i = 0 ; i < N ; ++i){
                if(vis[i]) continue;
                ans &= !dfs(g , vis , i , -1);
        }

        cout << (ans ? "Yes" : "No");

        return 0;
}
