#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

int32_t main(){
        ios::sync_with_stdio(false);
        cin.tie(nullptr);

        int N , M;
        cin >> N >> M;

        vector < int > A(N);
        for(int i = 0 ; i < N ; ++i) cin >> A[i];

        vector < int > B(N);
        for(int i = 0 ; i < N ; ++i) cin >> B[i];

        vector g(N , vector < int >());

        while(M--){
                int u , v;
                cin >> u >> v;
                --u , --v;
                g[u].push_back(v);
                g[v].push_back(u);
        }       

        vector < bool > vis(N , 0);

        bool ans = 1;

        for(int i = 0 ; i < N ; ++i){
                if(vis[i]) continue;
                queue < int > q;
                q.push(i);
                vis[i] = 1;
                i64 sum = 0;
                while(!q.empty()){
                        int u = q.front();
                        q.pop();
                        sum += B[u] - A[u];
                        for(auto v : g[u]){
                                if(!vis[v]){
                                        q.push(v);
                                        vis[v] = 1;
                                }
                        }
                }
                ans &= sum == 0;
        }

        cout << (ans ? "Yes" : "No");

        return 0;
}
