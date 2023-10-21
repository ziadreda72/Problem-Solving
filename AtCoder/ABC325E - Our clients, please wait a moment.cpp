#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

#define F first
#define S second

int32_t main(){
        ios::sync_with_stdio(false);
        cin.tie(nullptr);

        const i64 INF = (i64) 1e18;

        int N;
        cin >> N;

        i64 A , B , C;
        cin >> A >> B >> C;

        vector < vector < pair < int , i64 > > > g(N) , g2(N);
        
        for(int i = 0 ; i < N ; ++i){
                for(int j = 0 ; j < N ; ++j){
                        int D;
                        cin >> D;
                        if(i != j){
                                g[i].push_back({j , D * A});
                                g2[i].push_back({j , D * B + C});
                        }
                }
        }

        auto Dijkstra = [&](int s , vector < vector < pair < int , i64 > > > &g){
                vector < i64 > d(N , INF);
                d[s] = 0;
                priority_queue < pair < i64 , int > , vector < pair < i64 , int > > , greater <> > pq;
                pq.push({d[s] , s});
                while(!pq.empty()){
                        int u = pq.top().S;
                        pq.pop();
                        for(auto [v , w] : g[u]){
                                if(d[u] + w < d[v]){
                                        d[v] = d[u] + w;
                                        pq.push({d[v] , v});
                                }
                        }
                }

                return d;
        };

        auto d = Dijkstra(0 , g);
        auto d2 = Dijkstra(N - 1 , g2);

        i64 ans = INF;
        for(int i = 0 ; i < N ; ++i){
                ans = min(ans , d[i] + d2[i]);
        }

        cout << ans;

        return 0;
}
