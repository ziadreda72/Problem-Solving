#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

int32_t main(){
        ios::sync_with_stdio(false);
        cin.tie(nullptr);

        const int INF = (int) 1e9;

        int N , X , Y;
        cin >> N >> X >> Y;

        vector < vector < int > > g(N + 1);

        g[X].push_back(Y);
        g[Y].push_back(X);

        for(int i = 1 ; i + 1 <= N ; ++i){
                g[i].push_back(i + 1);
                g[i + 1].push_back(i);
        }

        vector < int > ans(N , 0);

        for(int i = 1 ; i <= N ; ++i){
                vector < int > d(N + 1 , INF);
                d[i] = 0;
                queue < int > q;
                q.push(i);
                while(!q.empty()){
                        int u = q.front();
                        q.pop();
                        for(auto v : g[u]){
                                if(d[u] + 1 < d[v]){
                                        d[v] = d[u] + 1;
                                        q.push(v);
                                }
                        }
                } 

                for(int j = i + 1 ; j <= N ; ++j){
                        ans[d[j]]++;
                }
        }

        for(int i = 1 ; i + 1 <= N ; ++i){
                cout << ans[i] << '\n';
        }

        return 0;
}
