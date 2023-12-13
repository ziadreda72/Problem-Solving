#include <bits/stdc++.h>

using namespace std;
using i64 = long long;
using ld = long double;

ld dp[2][1005][1005];
bool vis[2][1005][1005];

ld solve(int t , int w , int b){
        if(w == 0) 
                return (ld) 0.0;
        if(b == 0){
                if(t == 0)
                        return (ld) 1.0;
                return (ld) 0.0;
        }

        auto &ret = dp[t][w][b];
        if(vis[t][w][b])
                return ret;
        vis[t][w][b] = 1;

        ret = (ld) 0.0;

        ld p = ((ld) w / (ld) (w + b));

        if(t == 0){
                ret += p + solve(t ^ 1 , w , b - 1) * ((ld) 1.0 - p);
        }else{
                ld p2 = ((ld) w / (ld) (w + b - 1));
                ld p3 = ((ld) (b - 1) / (ld) (w + b - 1));
                ret += ((ld) 1.0 - p) * solve(t ^ 1 , w - 1 , b - 1) * p2;
                ret += (ld) solve(t ^ 1 , w , max(0 , b - 2)) * p3 * ((ld) 1.0 - p);
        }

        return ret;
}

int32_t main(){
        ios::sync_with_stdio(false);
        cin.tie(nullptr);

        int w , b;
        cin >> w >> b;

        cout << fixed << setprecision(20) << solve(0 , w , b);

        return 0;
}
