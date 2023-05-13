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
    int x = 0 , y = 0 , dir = 1;
    vector < pair < int , int > > ans;
    while (1){
        ans.emplace_back(x + 1 , y + 1);
        y += dir;
        if(y == m)
            dir *= -1 , y = m - 1 , x++;
        if(y == -1)
            dir *= -1 , y = 0 , x++;
        if(x == n)
            break;
    }
    for (int i = 0; i < k - 1; ++i) {
        cout << "2 ";
        cout << ans.back().F << ' ' << ans.back().S << ' ';
        ans.pop_back();
        cout << ans.back().F << ' ' << ans.back().S << '\n';
        ans.pop_back();
    }
    cout << ans.size() << ' ';
    while (ans.size())
        cout << ans.back().F << ' ' << ans.back().S << ' ' , ans.pop_back();
    return 0;
}
