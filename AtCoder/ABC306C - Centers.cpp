#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

int32_t main() {
        ios::sync_with_stdio(false);cin.tie(nullptr);
        cout.tie(nullptr);cout.precision(20);
        int n;
        cin >> n;
        map < int , vector < int > > mp;
        for (int i = 0; i < 3 * n; ++i) {
                int x;
                cin >> x;
                mp[x].push_back(i);
        }
        vector < pair < int , int > > ans;
        for(auto [key , val] : mp)
                ans.emplace_back(val[1] , key);
        sort(ans.begin(), ans.end());
        for(auto [x , y] : ans)
                cout << y << ' ';
        return 0;
}
