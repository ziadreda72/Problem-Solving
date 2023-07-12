#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

int32_t main() {
        ios::sync_with_stdio(false);cin.tie(nullptr);
        cout.tie(nullptr);cout.precision(20);
        int n , m , x , y , z , p;
        cin >> n >> m >> x >> y >> z >> p;
        vector < pair < int , int > > a(p);
        for (int i = 0; i < p; ++i) {
                cin >> a[i].first >> a[i].second;
        }
        x %= 4 , y %= 2 , z %= 4;
        while (x--){
                swap(n , m);
                for(auto& [r , c] : a){
                        swap(r , c);
                        c = m - c + 1;
                }
        }
        if (y){
                for(auto& [r , c] : a)
                        c = m - c + 1;
        }
        while (z--){
                swap(n , m);
                for(auto& [r , c] : a){
                        swap(r , c);
                        r = n - r + 1;
                }
        }
        for(auto [r , c] : a)
                cout << r << ' ' << c << '\n';
        return 0;
}
