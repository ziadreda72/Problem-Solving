#include <bits/stdc++.h>

using namespace std;
using i64 = long long;
using ld = long double;

#define F first
#define S second

int n;
vector < pair < pair < int , int > , int > > a;
i64 dp[125][1 << 18];

i64 solve(int i , int msk){
        if(i >= n){
                return 0;
        }
        auto &ret = dp[i][msk];
        if(ret != -1){
                return ret;
        }
        ret = solve(i + 1 , msk);
        int f = a[i].F.F , s = a[i].F.S , d = a[i].S;
        if(((msk >> f) & 1) == 0 && ((msk >> s) & 1) == 0){
                int new_msk = msk | (1 << f);
                new_msk |= (1 << s);
                ret = max(ret , solve(i + 1 , new_msk) + d);
        }
        return ret;
}

int32_t main(){
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        cin >> n;
        for(int i = 0 ; i < n ; ++i){
                for(int j = i + 1 ; j < n ; ++j){
                        int x;
                        cin >> x;
                        a.push_back({{i , j} , x});
                }
        }
        n = (int) a.size();
        memset(dp , -1 , sizeof dp);
        cout << solve(0 , 0);
        return 0;
}
