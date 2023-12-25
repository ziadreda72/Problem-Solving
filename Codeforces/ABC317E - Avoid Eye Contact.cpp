#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

const string direction = "><^v";
const int di[] = {0 , 0 , -1 , 1};
const int dj[] = {1 , -1 , 0 , 0};

int n , m;
vector < string > g;

bool check(int i , int j) {
        return (0 <= i && i < n) && (0 <= j && j < m) && g[i][j] == '.';
}

bool check2(int i , int j) {
        return (0 <= i && i < n) && (0 <= j && j < m) && (g[i][j] == '.' || g[i][j] == 'G');
}

int32_t main() {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);

        cin >> n >> m;

        g.resize(n);
        for (int i = 0 ; i < n ; ++i) cin >> g[i];

        vector vis(n , vector < bool > (m , 0));

        queue < tuple < int , int , int > > q;
        for (int i = 0 ; i < n ; ++i) {
                for (int j = 0 ; j < m ; ++j) {
                        if (g[i][j] != '.' && g[i][j] != '#' && g[i][j] != 'S' && g[i][j] != 'G') {
                                int t = direction.find(g[i][j]);
                                q.push({i , j , t});
                        }
                }
        }

        while (!q.empty()) {
                auto [i , j , t] = q.front();
                q.pop();
                vis[i][j] = 1;
                int ni = i + di[t] , nj = j + dj[t];
                if (check(ni , nj)) q.push({ni , nj , t});
        }

        for (int i = 0 ; i < n ; ++i) {
                for (int j = 0 ; j < m ; ++j) {
                        if (vis[i][j]) g[i][j] = '#';
                }
        }

        vector d(n , vector < int > (m , -1));

        queue < pair < int , int > > q2;
        for (int i = 0 ; i < n ; ++i) {
                for (int j = 0 ; j < m ; ++j) {
                        if (g[i][j] == 'S') {
                                d[i][j] = 0;
                                q2.emplace(i , j);
                        }
                }
        }

        while (!q2.empty()) {
                auto [i , j] = q2.front();
                q2.pop();
                for (int k = 0 ; k < 4 ; ++k) {
                        int ni = i + di[k];
                        int nj = j + dj[k];
                        if (check2(ni , nj) && d[ni][nj] == -1) {
                                d[ni][nj] = d[i][j] + 1;
                                q2.push({ni , nj});
                        }
                }
        }

        for (int i = 0 ; i < n ; ++i) {
                for (int j = 0 ; j < m ; ++j) {
                        if (g[i][j] == 'G') {
                                cout << d[i][j];
                                return 0;
                        }
                }
        }

        return 0;
}
