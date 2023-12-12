#include <bits/stdc++.h>

using namespace std;
using i64 = long long;
using ld = long double;

int n;
int A[55] , B[55];
ld P[55] , dp[55][1 << 16];
int vis[55][1 << 16] , id;

ld solve(int i , int msk){
        if(i >= n){
                return (ld) 1.0;
        }

        auto &ret = dp[i][msk];
        if(vis[i][msk] == id) return ret;
        vis[i][msk] = id;

        if(((1 << A[i]) & msk) == 0) ret += solve(i + 1 , msk | (1 << A[i])) * P[i];
        if(((1 << B[i]) & msk) == 0) ret += solve(i + 1 , msk | (1 << B[i])) * (1 - P[i]);

        return ret;
}

int32_t main(){
        ios::sync_with_stdio(false);
        cin.tie(nullptr);

        int tc;
        cin >> tc;

        while(tc--){
                for(int i = 0 ; i < 55 ; ++i){
                        for(int j = 0 ; j < (1 << 16) ; ++j){
                                dp[i][j] = 0.0;
                        }
                        A[i] = B[i] = 0;
                        P[i] = 0.0;
                }

                cin >> n;

                for(int i = 0 ; i < n ; ++i){
                        cin >> P[i] >> A[i] >> B[i];
                        P[i] /= 100.0;
                        --A[i] , --B[i];
                }

                id++;

                cout << fixed << setprecision(20);
                cout << solve(0 , 0) << '\n';
        }

        return 0;
}
