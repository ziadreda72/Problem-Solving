#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

#define F first
#define S second

int32_t main() {
    ios::sync_with_stdio(false);cin.tie(nullptr);
    cout.tie(nullptr);cout.precision(20);
    int n , m , k;
    cin >> n >> m >> k;
    map < int , pair < int , int > > mp[2];
    for (int i = 0; i < k; ++i) {
        int t , x , c;
        cin >> t >> x >> c;
        t-- , x--;
        mp[t][x] = {i , c};
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if(mp[0].contains(i) && mp[1].contains(j)){
                if(mp[0][i].F > mp[1][j].F) cout << mp[0][i].S << ' ';
                else cout << mp[1][j].S << ' ';
            }else{
                if(mp[0].contains(i)) cout << mp[0][i].S << ' ';
                else if(mp[1].contains(j)) cout << mp[1][j].S << ' ';
                else cout << "0 ";
            }
        }
        cout << '\n';
    }
    return 0;
}
