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
        int n;
        cin >> n;
        map < int , int > mp;
        for(int i = 0 ; i < n ; ++i){
                int x;
                cin >> x;
                mp[x]++;
                mp[x + 1]++;
                mp[x - 1]++;
        }
        int ans = 0;
        for(auto [x , y] : mp)
                ans = max(ans , y);
        cout << ans;
        return 0;
}
