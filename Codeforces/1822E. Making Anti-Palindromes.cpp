#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

void solveTC(){
        int n;
        cin >> n;

        string s;
        cin >> s;

        if(n & 1){
                cout << -1;
                return;
        }

        vector < int > cnt(26 , 0);
        for(auto c : s) cnt[c - 'a']++;

        for(auto i : cnt){
                if(i * 2 > n){
                        cout << -1;
                        return;
                }
        }

        int ans = 0;

        fill(cnt.begin() , cnt.end() , 0);

        for(int i = 0 ; i * 2 < n ; ++i){
                ans += s[i] == s[n - i - 1];
                cnt[s[i] - 'a'] += s[i] == s[n - i - 1];
        }

        ans = (ans + 1) / 2;

        for(auto x : cnt) ans = max(ans , x);

        cout << ans;
}

int32_t main(){
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        
        int tc;
        cin >> tc;
        
        while (tc--){
                solveTC();
                cout << '\n';
        }
        
        return 0;
}
