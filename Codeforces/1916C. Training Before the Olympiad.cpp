#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

const int MAX = (int) 1e5;

i64 dp[MAX + 10];

void solveTC(){
        int n;
        cin >> n;

        vector < i64 > a(n) , cnt(n) , pref(n);
        for (int i = 0 ; i < n ; ++i) {
                cin >> a[i];
                cnt[i] = a[i] & 1;
                if (i) {
                        pref[i] = pref[i - 1] + a[i];
                        cnt[i] += cnt[i - 1];
                }else {
                        pref[i] = a[i];
                }
        }

        cout << pref[0] << ' ';
        for (int i = 1 ; i < n ; ++i) {
                cout << pref[i] - dp[cnt[i]] << ' ';
        }
}

int32_t main(){
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        
        dp[0] = 0 , dp[1] = 1 , dp[2] = 0;
        for (int i = 3 ; i <= MAX ; ++i) {
                dp[i] = 1 + dp[i - 3];
        }

        int tc;
        cin >> tc;
        
        while (tc--){
                solveTC();
                cout << '\n';
        }
        
        return 0;
}
