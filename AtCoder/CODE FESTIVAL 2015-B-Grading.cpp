#include <bits/stdc++.h>

using namespace std;
using i64 = long long;
using ld = long double;

#define F first
#define S second

int32_t main(){
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        int n , m;
        cin >> n >> m;
        vector < int > cnt(m + 1 , 0);
        for(int i = 0 ; i < n ; ++i){
                int x;
                cin >> x;
                cnt[x]++;
        }
        auto it = max_element(cnt.begin() , cnt.end());
        int mx = *it , ans = it - cnt.begin();
        if(2 * mx > n)
                cout << ans;
        else
                cout << '?';
        cout << '\n';
        return 0;
}
