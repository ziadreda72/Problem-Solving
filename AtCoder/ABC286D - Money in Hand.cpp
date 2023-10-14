#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

int32_t main(){
        ios::sync_with_stdio(false);
        cin.tie(nullptr);

        int N , X;
        cin >> N >> X;

        vector < int > a(N) , b(N);
        for(int i = 0 ; i < N ; ++i) cin >> a[i] >> b[i];

        vector dp(N + 1 , vector < bool > (X + 1 , false));

        dp[0][0] = 1;
        for(int i = 0 ; i < N ; ++i){
                for(int j = 0 ; j <= X ; ++j){
                        if(dp[i][j] == false) continue;
                        for(int k = 0 ; k <= a[i] * b[i] ; k += a[i]){
                                if(j + k <= X){
                                        dp[i + 1][j + k] = dp[i][j];
                                }else{
                                        break;
                                }
                        }
                }
        }

        cout << (dp[N][X] ? "Yes" : "No");

        return 0;
}
