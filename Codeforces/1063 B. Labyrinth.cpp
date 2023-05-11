#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

#define F first
#define S second

const int OO = (int) 2e7;
const int dr[] = {0 , 0 , 1 , -1};
const int dc[] = {-1 , 1 , 0 , 0};

int r , c , st_r , st_c , x , y;
vector < vector < char > > g;
vector < vector < int > > d;
vector < vector < bool > > vis;

bool check(int nr , int nc){
    return ((0 <= nr && nr < r) && (0 <= nc && nc < c)) && g[nr][nc] != '*';
}

int32_t main() {
    ios::sync_with_stdio(false);cin.tie(nullptr);
    cout.tie(nullptr);cout.precision(20);
    cin >> r >> c >> st_r >> st_c >> x >> y;
    st_r-- , st_c--;
    g = vector < vector < char > > (r , vector < char > (c));
    d = vector < vector < int > > (r , vector < int > (c , OO));
    vis = vector < vector < bool > > (r , vector < bool > (c , 0));
    for (int i = 0; i < r; ++i) {
        for (int j = 0; j < c; ++j) {
            cin >> g[i][j];
        }
    }
    deque < pair < int , int > > q;
    q.emplace_front(st_r , st_c);
    d[st_r][st_c] = 0;
    while (!q.empty()){
        int cur_r = q.front().F , cur_c = q.front().S;
        q.pop_front();
        if(vis[cur_r][cur_c])
            continue;
        vis[cur_r][cur_c] =  1;
        for (int i = 0; i < 4; ++i) {
            int nr = cur_r + dr[i];
            int nc = cur_c + dc[i];
            if(!check(nr , nc))
                continue;
            int w = (dr[i] == 0 && dc[i] == -1 ? 1 : 0);
            if(d[cur_r][cur_c] + w < d[nr][nc]){
                d[nr][nc] = d[cur_r][cur_c] + w;
                w == 1 ? q.emplace_back(nr , nc) : q.emplace_front(nr , nc);
            }
        }
    }
    int ans = 0;
    for (int i = 0; i < r; ++i) {
        for (int j = 0; j < c; ++j) {
            if(d[i][j] == OO) continue;
            int L = d[i][j];
            int R = L + (j - st_c);
            ans += L <= x && R <= y;
        }
    }
    cout << ans;
    return 0;
}
