#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

const int inf = (int) 1e9;

int32_t main(){
        ios::sync_with_stdio(false);
        cin.tie(nullptr);

        int H , N;
        cin >> H >> N;

        vector < int > dp(H + 1 , inf);
        dp[0] = 0;
        for(int i = 0 ; i < N ; ++i){
                int a , b;
                cin >> a >> b;
                for(int j = 0 ; j < H ; ++j){
                        int nj = min(H , j + a);
                        dp[nj] = min(dp[nj] , dp[j] + b);
                }
        }

        cout << dp[H];

        return 0;
}
