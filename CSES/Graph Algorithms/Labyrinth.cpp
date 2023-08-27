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
        array < int , 2 > st{} , en{};
        for(int i = 0 ; i < n ; ++i){
                for(int j = 0 ; j < m ; ++j){
                        cin >> g[i][j];
                        if(g[i][j] == 'A')
                                st[0] = i , st[1] = j;
                        if(g[i][j] == 'B')
                                en[0] = i , en[1] = j;
                }

        }
        vector < vector < bool > > vis(n , vector < bool > (m , false));
        vector < vector < char > > d(n , vector < char > (m));
        map < array < int , 2 > , array < int , 2 > > par;
        vector < int > dr = {0 , 0 , -1 , 1};
        vector < int > dc = {-1 , 1 , 0 , 0};
        vector < char > dir = {'L' , 'R' , 'U' , 'D'};
        queue < array < int , 2 > > q;
        q.push(st);
        vis[st[0]][st[1]] = 1;
        auto check = [&](int r , int c){
                return (0 <= r && r < n) && (0 <= c && c < m) && !vis[r][c] && g[r][c] != '#';
        };
        auto update = [&](array < int , 2 > cur , array < int , 2 > nxt , char dir){
                d[nxt[0]][nxt[1]] = dir;
                par[nxt] = cur;
                vis[nxt[0]][nxt[1]] = 1;
                q.push(nxt);
        };
        while(!q.empty()){
                auto cur = q.front();
                int r = cur[0] , c = cur[1];
                q.pop();
                for(int i = 0 ; i < 4 ; ++i){
                        int nr = r + dr[i];
                        int nc = c + dc[i];
                        if(check(nr , nc))
                                update(cur , array < int , 2 > {nr , nc} , dir[i]);
                }
        }
        if(!vis[en[0]][en[1]]){
                cout << "NO";
                return 0;
        }
        cout << "YES\n";
        string ans;
        for(auto i = en ; i != st ; i = par[i])
                ans += d[i[0]][i[1]];
        reverse(ans.begin() , ans.end());
        cout << (int) ans.size() << '\n' << ans;
        return 0;
}
