#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

int32_t main(){
        ios::sync_with_stdio(false);
        cin.tie(nullptr);

        int N;
        cin >> N;

        vector < vector < array < int , 2 > > > g(N + 1);

        for(int i = 0 ; i + 1 < N ; ++i){
                int a , b , c;
                cin >> a >> b >> c;

                g[a].push_back({b , c});
                g[b].push_back({a , c});
        }

        int Q , K;
        cin >> Q >> K;

        vector < i64 > d(N + 1 , -1);
        d[K] = 0;
        
        queue < int > q;
        q.push(K);

        while(!q.empty()){
                int u = q.front();
                q.pop();

                for(auto [v , w] : g[u]){
                        if(d[v] == -1){
                                d[v] = d[u] + w;
                                q.push(v);
                        }
                }
        }

        while(Q--){
                int x , y;
                cin >> x >> y;

                cout << d[x] + d[y] << '\n';
        }

        return 0;
}
