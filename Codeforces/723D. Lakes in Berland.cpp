#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

#define F first
#define S second

const int dr[] = {0 , 0 , 1 , -1};
const int dc[] = {-1 , 1 , 0 , 0};

int n , m , k;
vector < vector < char > > g;
vector < vector < bool > > vis;
bool ok;

bool check(int r , int c){
    return ((0 <= r && r < n) && (0 <= c && c < m));
}

int dfs(int r , int c){
    vis[r][c] = 1;
    int ret = 1;
    for (int i = 0; i < 4; ++i) {
        int nr = r + dr[i];
        int nc = c + dc[i];
        if(!check(nr , nc))
            ok = false;
        else if(g[nr][nc] != '*' && !vis[nr][nc])
            ret += dfs(nr , nc);
    }
    return ret;
}

void dfs2(int r , int c){
    vis[r][c] = 1;
    g[r][c] = '*';
    for (int i = 0; i < 4; ++i) {
        int nr = r + dr[i];
        int nc = c + dc[i];
        if(check(nr , nc) && g[nr][nc] != '*' && !vis[nr][nc])
            dfs2(nr , nc);
    }
}

int32_t main() {
    ios::sync_with_stdio(false);cin.tie(nullptr);
    cout.tie(nullptr);cout.precision(20);
    cin >> n >> m >> k;
    g = vector < vector < char > > (n , vector < char > (m));
    vis = vector < vector < bool > > (n , vector < bool > (m , 0));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> g[i][j];
        }
    }
    vector < pair < int , pair < int , int > > > v;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if(vis[i][j] || g[i][j] == '*')
                continue;
            ok = true;
            int x = dfs(i , j);
            if(ok)
                v.emplace_back(x , make_pair(i , j));
        }
    }
    sort(v.rbegin(), v.rend());
    vis = vector < vector < bool > > (n , vector < bool > (m , 0));
    int ans = 0;
    while ((int) v.size() > k){
        ans += v.back().F;
        int r = v.back().S.F;
        int c = v.back().S.S;
        dfs2(r , c);
        v.pop_back();
    }
    cout << ans << '\n';
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cout << g[i][j];
        }
        cout << '\n';
    }
    return 0;
}
