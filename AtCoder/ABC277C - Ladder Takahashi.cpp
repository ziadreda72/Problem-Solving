#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

map < int , vector < int > > g;
set < int > vis;

int dfs(int u){
        vis.insert(u);
        int ret = u;

        for(auto v : g[u]){
                if(vis.count(v)) continue;
                ret = max(ret , dfs(v));
        }

        return ret;
}

int32_t main(){
        ios::sync_with_stdio(false);
        cin.tie(nullptr);

        int N;
        cin >> N;

        while(N--){
                int A , B;
                cin >> A >> B;

                g[A].push_back(B);
                g[B].push_back(A);
        }

        cout << dfs(1);

        return 0;
}
