#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

int32_t main(){
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        int n , m;
        cin >> n >> m;
        vector < string > s(n);
        for (int i = 0; i < n; ++i) {
                cin >> s[i];
        }
        vector < vector < bool > > vis(n , vector < bool > (m , 0));
        auto vis2 = vis;
        vis[1][1] = vis2[1][1] = 1;
        queue < pair < int , int > > q;
        q.emplace(1 , 1);
        vector< int > dr = {1, 0, -1, 0};
        vector< int > dc = {0, 1, 0, -1};
        while (!q.empty()){
                int r = q.front().first , c = q.front().second;
                q.pop();
                for (int i = 0; i < 4; ++i) {
                        int nr = r , nc = c;
                        while (s[nr + dr[i]][nc + dc[i]] == '.'){
                                nr += dr[i];
                                nc += dc[i];
                                vis2[nr][nc] = 1;
                        }
                        if(!vis[nr][nc]){
                                vis[nr][nc] = 1;
                                q.emplace(nr , nc);
                        }
                }
        }
        int ans = 0;
        for (int i = 0; i < n; ++i) {
                for (int j = 0; j < m; ++j) {
                        ans += vis2[i][j];
                }
        }
        cout << ans;
        return 0;
}
