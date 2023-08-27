#include <bits/stdc++.h>

using namespace std;

#define F first
#define S second

int32_t main(){
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        int n , m;
        cin >> n >> m;
        vector < vector < char > > g(n , vector < char > (m));
        for(int i = 0 ; i < n ; ++i)
                for(int j = 0 ; j < m ; ++j)
                        cin >> g[i][j];
        int ans = 0;
        vector < vector < bool > > vis(n , vector < bool > (m , false));
        vector < int > dr = {0 , 0 , -1 , 1};
        vector < int > dc = {-1 , 1 , 0 , 0};
        for(int i = 0 ; i < n ; ++i){
                for(int j = 0 ; j < m ; ++j){
                        if(g[i][j] == '#' || vis[i][j])
                                continue;
                        ans++;
                        queue < pair < int , int > > q;
                        vis[i][j] = true;
                        q.emplace(i , j);
                        while(!q.empty()){
                                int r = q.front().F , c = q.front().S;
                                q.pop();
                                for(int k = 0 ; k < 4 ; ++k){
                                        int nr = r + dr[k];
                                        int nc = c + dc[k];
                                        if((0 <= nr && nr < n) && (0 <= nc && nc < m) && !vis[nr][nc] && g[nr][nc] != '#'){
                                                vis[nr][nc] = true;
                                                q.emplace(nr , nc);
                                        }
                                }
                        }
                }
        }
        cout << ans;
        return 0;
}
