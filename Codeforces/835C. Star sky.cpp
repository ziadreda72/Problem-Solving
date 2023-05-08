#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

#define F first
#define S second

const int N = 105;

int n , q , c;
int a[15][N][N];

int32_t main() {
    ios::sync_with_stdio(false);cin.tie(nullptr);
    cout.tie(nullptr);cout.precision(20);
    cin >> n >> q >> c;
    for (int i = 0; i < n; ++i) {
        int x , y , s;
        cin >> x >> y >> s;
        a[s][x][y]++;
    }
    for (int i = 0; i <= c; ++i) {
        for (int j = 1; j <= 100; ++j) {
            for (int k = 1; k <= 100; ++k) {
                a[i][j][k] += a[i][j][k - 1];
            }
        }
        for (int j = 1; j <= 100; ++j) {
            for (int k = 1; k <= 100; ++k) {
                a[i][k][j] += a[i][k - 1][j];
            }
        }
    }
    while (q--){
        int t , x , y , x2 , y2;
        cin >> t >> x >> y >> x2 >> y2;
        int ans = 0;
        for (int i = 0; i <= c; ++i) {
            ans += ((t + i) % (c + 1)) * (a[i][x2][y2] - a[i][x2][y - 1] - a[i][x - 1][y2] + a[i][x - 1][y - 1]);
        }
        cout << ans << '\n';
    }
    return 0;
}
