#include <bits/stdc++.h>

using namespace std;
using i64 = long long;
using ld = long double;

#define F first
#define S second

int32_t main(){
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        int n , k;
        cin >> n >> k;
        vector < string > s(n);
        for(int i = 0 ; i < n ; ++i){
                cin >> s[i];
        }
        int ans = 0;
        for(int msk = 1 ; msk < (1 << n) ; ++msk){
                if(__builtin_popcount(msk) < k){
                        continue;
                }
                map < char , int > mp;
                for(int i = 0 ; i < n ; ++i){
                        if((msk >> i) & 1){
                                for(auto c : s[i]) mp[c]++;
                        }
                }
                int cnt = 0;
                for(auto [c , x] : mp){
                        cnt += x == k;
                }
                ans = max(ans , cnt);
        }
        cout << ans;
        return 0;
}
