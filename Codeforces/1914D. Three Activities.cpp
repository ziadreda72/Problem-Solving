#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

int n;
vector < vector < array < int , 2 > > > a;
vector < vector < int > > dp;

int solve(int i , int msk) {
        if(i >= n) {
                return msk == 7 ? 0 : INT32_MIN;
        }

        auto &ret = dp[i][msk];
        if(ret != -1) {
                return ret;
        }

        ret = solve(i + 1 , msk);

        for(auto [x , t] : a[i]) {
                if((msk >> t) & 1) continue;
                ret = max(ret , solve(i + 1 , msk | (1 << t)) + x);
        }

        return ret;
}

void solveTC(){
        a.clear();
        dp.clear();
        
        cin >> n;

        a.resize(n);

        for(int t = 0 ; t < 3 ; ++t) {
                for(int i = 0 ; i < n ; ++i) {
                        int x;
                        cin >> x;
                        a[i].push_back({x , t});
                }
        }

        dp.assign(n + 5 , vector < int > (1 << 3 , -1));

        cout << solve(0 , 0);
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
