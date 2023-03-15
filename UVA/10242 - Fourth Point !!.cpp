#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

#define F first
#define S second

int32_t main()
{
    ios::sync_with_stdio(false);cin.tie(nullptr);
    cout.tie(nullptr);cout.precision(20);
    pair < double , double > a , b , c , d;
    while (cin >> a.F >> a.S >> b.F >> b.S >> c.F >> c.S >> d.F >> d.S){
        map < pair < double , double > , int > mp;
        mp[a]++;
        mp[b]++;
        mp[c]++;
        mp[d]++;
        pair < double , double > C;
        pair < double , double > ans = {0.0 , 0.0};
        for(auto [p , x] : mp){
            if(x == 2){
                C = p;
            }else{
                ans.F += p.F;
                ans.S += p.S;
            }
        }
        cout << fixed << setprecision(3);
        cout << ans.F - C.F << ' ' << ans.S - C.S << '\n';
    }
    return 0;
}
