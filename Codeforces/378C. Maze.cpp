#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

#define F first
#define S second

const int N = 505;
const int di[] = {0 , 0 , 1 , -1};
const int dj[]=  {1 , -1 , 0 , 0};

int n , m , k , s , x;
char g[N][N];
bool vis[N][N];

bool check(int i , int j){
    return (0 <= i && i < n) && (0 <= j && j < m);
}

void dfs(int i , int j){
    if(!x) return;
    vis[i][j] = true;
    x--;
    for (int l = 0; l < 4; ++l) {
        int ni = i + di[l];
        int nj = j + dj[l];
        if(check(ni , nj) && !vis[ni][nj] && g[ni][nj] == '.') dfs(ni , nj);
    }
}

int32_t main() {
    ios::sync_with_stdio(false);cin.tie(nullptr);
    cout.tie(nullptr);cout.precision(20);
    cin >> n >> m >> k;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> g[i][j];
            s += g[i][j] == '.';
        }
    }
    x = s - k;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if(g[i][j] == '.'){
                dfs(i , j);
                break;
            }
        }
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if(vis[i][j] || g[i][j] == '#') cout << g[i][j];
            else cout << 'X';
        }
        cout << '\n';
    }
    return 0;
}
