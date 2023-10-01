#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

const i64 INF = (i64) 1e12;

int n , k , p;
vector < pair < int , vector < int > > > a;
map < pair < int , vector < int > > , i64 > dp;

i64 solve(int i , vector < int > v){
        if(i >= n){
                bool ok = 1;
                for(auto x : v) ok &= x >= p;
                if(ok){
                        return 0;
                }
                return INF;
        }

        if(dp.find({i , v}) != dp.end()){
                return dp[{i , v}];
        }

        i64 ret = solve(i + 1 , v);

        vector < int > v2 = v;
        for(int j = 0 ; j < k ; ++j){
                v2[j] = min(p , v2[j] + a[i].S[j]);
        }
 
        ret = min(ret , solve(i + 1 , v2) + a[i].F);

        return dp[{i , v}] = ret;
}

int32_t main(){
        ios::sync_with_stdio(false);
        cin.tie(nullptr);

        cin >> n >> k >> p;
        
        a.resize(n);
        for(int i = 0 ; i < n ; ++i){
                cin >> a[i].F;
                for(int j = 0 ; j < k ; ++j){
                        int x;
                        cin >> x;
                        a[i].S.push_back(x);
                }
        }

        vector < int > v(k , 0);
        i64 ans = solve(0 , v);
        if(ans >= INF) ans = -1;
        
        cout << ans;

        return 0;
}
