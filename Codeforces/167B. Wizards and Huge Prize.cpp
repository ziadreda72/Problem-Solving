#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

const int MAX = 205;

int N , L , K , a[MAX];
double p[MAX] , dp[MAX][MAX][MAX + MAX];
bool vis[MAX][MAX][MAX + MAX];

double solve(int i = 0 , int l = 0 , int k = K + 200) {
        if(i >= N) {
                return l >= L && k >= 200;
        }

        auto &ret = dp[i][l][k];
        if(vis[i][l][k]) {
                return ret;
        }
        vis[i][l][k] = 1;
        
        
        ret = (solve(i + 1 , l , k) * (1.0 - p[i])) + (solve(i + 1 , l + 1 , min(400 , k + a[i])) * p[i]);

        return ret;
}

int32_t main(){
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        
        cin >> N >> L >> K;

        for(int i = 0 ; i < N ; ++i){
                cin >> p[i];
                p[i] /= (double) 100.0;
        }

        for(int i = 0 ; i < N ; ++i) cin >> a[i];

        cout << fixed << setprecision(20) << solve();

        return 0;
}
