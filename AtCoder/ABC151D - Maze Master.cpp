#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

const int INF = 1E9;
const int dr[] = {0 , 0 , -1 , 1};
const int dc[] = {-1 , 1 , 0 , 0};

int R , C;
vector < string > g;

bool check(int r , int c){
        return (0 <= r && r < R) && (0 <= c && c < C) && g[r][c] != '#';
}

int bfs(int st_r , int st_c){
        vector d(R , vector < int > (C , INF));
        d[st_r][st_c] = 0;

        queue < array < int , 2 > > q;
        q.push({st_r , st_c});
        
        while(!q.empty()){
                auto r = q.front()[0] , c = q.front()[1];
                q.pop();
                for(int i = 0 ; i < 4 ; ++i){
                                int nr = r + dr[i];
                                int nc = c + dc[i];
                                if(check(nr , nc) && ((d[r][c] + 1) < d[nr][nc])){
                                        d[nr][nc] = d[r][c] + 1;
                                        q.push({nr ,nc});
                                }
                }
        }

        int ret = 0;
        for(int i = 0 ; i < R ; ++i){
                for(int j = 0 ; j < C ; ++j){
                        if(g[i][j] != '#' && d[i][j] < INF){
                                ret = max(ret , d[i][j]);
                        }
                }
        }

        return ret;
}

int32_t main(){
        ios::sync_with_stdio(false);
        cin.tie(nullptr);

        cin >> R >> C;

        g.resize(R);
        for(int i = 0 ; i < R ; ++i) cin >> g[i];


        int ans = 0;
        for(int i = 0 ; i < R ; ++i){
                for(int j = 0 ; j < C ; ++j){
                        if(g[i][j] == '#') continue;
                        ans = max(ans , bfs(i , j));
                }
        }

        cout << ans;

        return 0;
}
