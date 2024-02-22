#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

const string d = "LRUD";
const int dr[] = {0 , 0 , -1 , 1};
const int dc[] = {-1 , 1 , 0 , 0};

int32_t main(){
        ios::sync_with_stdio(false);
        cin.tie(nullptr);

        int h , w , n;
        cin >> h >> w >> n;

        string s;
        cin >> s;

        vector < string > g(h);
        for (int i = 0 ; i < h ; ++i) cin >> g[i];

        auto check = [&](int r , int c) {
                return (0 <= r && r < h) && (0 <= c && c < w) && g[r][c] != '#';
        };

        auto possible = [&](int r , int c) {
                for (auto &dir : s) {
                        int i = d.find(dir);
                        if (!check(r + dr[i] , c + dc[i])) return false;
                        r += dr[i];
                        c += dc[i];
                }
                return true;
        };

        int ans = 0;
        for (int i = 0 ; i < h ; ++i) {
                for (int j = 0 ; j < w ; ++j) {
                        if (g[i][j] == '#') continue;
                        ans += possible(i , j);
                }
        }

        cout << ans;

        return 0;
}
