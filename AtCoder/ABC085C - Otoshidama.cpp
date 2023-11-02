#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

int32_t main(){
        ios::sync_with_stdio(false);
        cin.tie(nullptr);

        int N , Y;
        cin >> N >> Y;

        Y /= 1000;

        vector dp(N + 1 , vector < bool > (Y + 1 , 0));

        dp[0][0] = 1;
        for(int i = 0 ; i < N ; ++i){
                for(int j = 0 ; j <= Y ; ++j){
                        if(dp[i][j]){
                                for(auto k : {1 , 5 , 10}){
                                        if(j + k <= Y){
                                                dp[i + 1][j + k] = 1;
                                        }else break;
                                }
                        }
                }
        }

        if(dp[N][Y] == 0){
                cout << "-1 -1 -1";
                return 0;
        }

        int x = 0 , y = 0 , z = 0;

        while(N--){
                if(dp[N][Y - 1]){
                        z++;
                        Y--;
                }else if(dp[N][Y - 5]){
                        y++;
                        Y -= 5;
                }else{
                        x++;
                        Y -= 10;
                }

        }

        cout << x << ' ' << y << ' ' << z;

        return 0;
}
