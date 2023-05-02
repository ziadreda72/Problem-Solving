#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

#define F first
#define S second

int32_t main() {
    ios::sync_with_stdio(false);cin.tie(nullptr);
    cout.tie(nullptr);cout.precision(20);
    int n , m;
    cin >> n >> m;
    vector < string > v(n);
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
    }
    vector < vector < int > > b(n , vector < int > (m , 0));
    for (int i = 0; i < m; ++i) {
        b[n - 1][i] = 1;
    }
    for (int i = 0; i + 1 < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if(v[i][j] > v[i + 1][j]) b[i][j] = 0;
            else if(v[i][j] == v[i + 1][j]) b[i][j] = 1;
            else b[i][j] = 2;
        }
    }
    vector < bool > vis(m , 0);
    while (true){
        int x = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if(vis[j]) continue;
                if(b[i][j] == 0){
                    vis[j] = 1;
                    x++;
                    break;
                }else if(b[i][j] == 2) {
                    break;
                }else{
                    for (int k = 0; k < m; ++k) {
                        if(vis[k]) continue;
                        if(b[i][k] == 0){
                            x++;
                            vis[k] = 1;
                        }else{
                            break;
                        }
                    }
                }
            }
        }
        if(!x) break;
    }
    cout << accumulate(vis.begin(), vis.end() , 0);
    return 0;
}
