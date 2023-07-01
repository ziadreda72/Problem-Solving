#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

const int N = 1005 , inf = 1e9;
const int dr[] = {0 , 0 , -1 , 1};
const int dc[] = {-1 , 1 , 0 , 0};

int n , m , k;
char g[N][N];
int x , y , x2 , y2;
int d[N][N];

bool check(int r , int c){
          return (0 <= r && r < n && 0 <= c && c < m) && g[r][c] == '.';
}

int32_t main() {
          ios::sync_with_stdio(false);cin.tie(nullptr);
          cout.tie(nullptr);cout.precision(20);
          cin >> n >> m >> k;
          for (int i = 0; i < n; ++i) {
                    for (int j = 0; j < m; ++j) {
                              cin >> g[i][j];
                              d[i][j] = inf;
                    }
          }
          cin >> x >> y >> x2 >> y2;
          x-- , y-- , x2-- , y2--;
          queue < array < int , 3 > > q;
          d[x][y] = 0;
          q.push({0 , x , y});
          while (!q.empty()){
                    int dep = q.front()[0];
                    int r = q.front()[1] , c = q.front()[2];
                    q.pop();
                    for (int i = 0; i < 4; ++i) {
                              int nr = r , nc = c;
                              for (int j = 0; j < k; ++j) {
                                        nr += dr[i] , nc += dc[i];
                                        if(check(nr , nc) && d[nr][nc] > dep){
                                                  if(d[nr][nc] == dep + 1)
                                                            continue;
                                                  d[nr][nc] = dep + 1;
                                                  q.push({d[nr][nc] , nr , nc});
                                        }else
                                                  break;

                              }
                    }
          }
          if(d[x2][y2] == inf)
                    d[x2][y2] = -1;
          cout << d[x2][y2];
          return 0;
}
