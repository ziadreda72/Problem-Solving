#include <bits/stdc++.h>

using namespace std;
using i64 = long long;
using i128 = __int128;
using ld = long double;

#define F first
#define S second

int32_t main(){
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        int n , m;
        cin >> n >> m;
        vector < pair < int , int > > a(n) , a2(m);
        for(int i = 0 ; i < n ; ++i){
                cin >> a[i].F >> a[i].S;
        }
        for(int i = 0 ; i < m ; ++i){
                cin >> a2[i].F >> a2[i].S;
        }
        for(auto [x , y] : a){
                vector < pair < int , int > > ans;
                for(int i = 0 ; i < m ; ++i){
                        int x2 = a2[i].F;
                        int y2 = a2[i].S;
                        ans.emplace_back(abs(x - x2) + abs(y - y2) , i + 1);
                }
                sort(ans.begin() , ans.end());
                cout << ans.front().S << '\n';
        }
        return 0;
}
