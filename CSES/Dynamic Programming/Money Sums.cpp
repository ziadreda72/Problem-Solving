#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

const int MAX = (int) 1e5;

bool dp[MAX + 1];

int32_t main(){
        ios::sync_with_stdio(false);
        cin.tie(nullptr);

        int n;
        cin >> n;

        dp[0] = 1;
        for(int i = 0 ; i < n ; ++i){
                int x;
                cin >> x;
                for(int j = MAX ; j >= 0 ; --j){
                        if(dp[j] == 0) continue;
                        if(j + x  <= MAX){
                                dp[j + x] = 1;
                        }
                }
        }

        vector < int > ans;
        for(int i = 1 ; i <= MAX ; ++i){
                if(dp[i]) ans.push_back(i);
        }

        cout << ans.size() << '\n';
        for(auto x : ans) cout << x << ' ';

        return 0;
}
