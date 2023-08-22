#include <bits/stdc++.h>

using namespace std;
using i64 = long long;
using i128 = __int128;
using ld = long double;

#define F first
#define S second

const int N = 55;
const int dr[] = {0 , 0 , -1 , 1};
const int dc[] = {-1 , 1 , 0 , 0};

int n , m;
char g[N][N];
bool vis[N][N];

bool check(int r , int c){
        return (0 <= r && r < n && 0 <= c && c < m) && !vis[r][c] && g[r][c] != '.';
}

int cnt;

void dfs(int r , int c){
        vis[r][c] = 1;
        cnt++;
        for(int i = 0 ; i < 4 ; ++i){
                int nr = r + dr[i];
                int nc = c + dc[i];
                if(check(nr , nc))
                        dfs(nr , nc);
        }
}

int32_t main(){
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        cin >> n >> m;
        for(int i = 0 ; i < n ; ++i){
                for(int j = 0 ; j < m ; ++j){
                        cin >> g[i][j];
                }
        }
        bool ans = 1;
        for(int i = 0 ; i < n ; ++i){
                for(int j = 0 ; j < m ; ++j){
                        if(vis[i][j] || g[i][j] == '.')
                                continue;
                        cnt = 0;
                        dfs(i , j);
                        ans &= cnt >= 2;
                }
        }
        cout << (ans ? "Yes" : "No");
        return 0;
}
