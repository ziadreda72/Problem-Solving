#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

int32_t main(){
        ios::sync_with_stdio(false);
        cin.tie(nullptr);

        const int INF = (int) 1e9;

        int N , M;
        cin >> N >> M;

        vector < vector < array < int , 2 > > > g(10);

        for(int i = 0 ; i < 10 ; ++i){
                for(int j = 0 ; j < 10 ; ++j){
                        int c;
                        cin >> c;

                        if(i != j){
                                g[i].push_back({j , c});
                        }
                }
        }

        vector < int > mn(10 , INF);
        for(int i = 0 ; i < 10 ; ++i){
                vector < int > d(10 , INF);
                d[i] = 0;

                priority_queue < array < int , 2 > , vector < array < int , 2 > > , greater <> > q;
                q.push({0 , i});

                while(!q.empty()){
                        int u = q.top()[1];
                        q.pop();

                        for(auto [v , c] : g[u]){
                                if(d[u] + c < d[v]){
                                        d[v] = d[u] + c;
                                        q.push({d[v] , v});
                                }
                        }
                }

                mn[i] = d[1];
        }

        int ans = 0;

        for(int i = 0 ; i < N ; ++i){
                for(int j = 0 ; j < M ; ++j){
                        int a;
                        cin >> a;

                        if(a != -1){
                                ans += mn[a];
                        }
                }
        }

        cout << ans;

        return 0;
}
