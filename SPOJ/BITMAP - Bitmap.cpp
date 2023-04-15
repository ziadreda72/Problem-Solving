#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

#define F first
#define S second

const int OO = (int) 1e8;
const int di[] = {0 , 0 , -1 , 1};
const int dj[] = {-1 , 1 , 0 , 0};

int n , m;

bool check(int i , int j){
    return (0 <= i && i < n) && (0 <= j && j < m);
}

void solve() {
    cin >> n >> m;
    vector < vector < char > > g(n , vector < char > (m));
    vector < vector < int > > d(n , vector < int > (m , OO));
    queue < pair < int , int > > q;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> g[i][j];
            if(g[i][j] == '1') q.emplace(i , j) , d[i][j] = 0;
        }
    }
    while (!q.empty()){
        pair < int , int > cur = q.front();
        q.pop();
        for (int i = 0; i < 4; ++i) {
            int ni = cur.F + di[i];
            int nj = cur.S + dj[i];
            if(check(ni , nj)){
                if(d[cur.F][cur.S] + 1 < d[ni][nj]){
                    d[ni][nj] = d[cur.F][cur.S] + 1;
                    q.emplace(ni , nj);
                }
            }
        }
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cout << d[i][j] << ' ';
        }
        cout << '\n';
    }
}

int32_t main() {
    ios::sync_with_stdio(false);cin.tie(nullptr);
    cout.tie(nullptr);cout.precision(20);
    int tc = 1;
    cin >> tc;
    while(tc--){
        solve();
    }
    return 0;
}
