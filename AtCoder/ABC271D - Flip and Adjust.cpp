#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

int32_t main(){
        ios::sync_with_stdio(false);
        cin.tie(nullptr);

        int N , S;
        cin >> N >> S;

        vector < int > A(N) , B(N);
        for(int i = 0 ; i < N ; ++i) cin >> A[i] >> B[i];

        vector dp(N + 1 , vector < bool > (S + 1 , false));

        dp[0][0] = 1;
        for(int i = 0 ; i < N ; ++i){
                for(int j = 0 ; j <= S ; ++j){
                        if(dp[i][j]){
                                if(j + A[i] <= S) dp[i + 1][j + A[i]] = 1;
                                if(j + B[i] <= S) dp[i + 1][j + B[i]] = 1;
                        }
                }
        }

        if(dp[N][S]){
                cout << "Yes\n";
                string ans;
                for(int i = N - 1 ; i >= 0 ; --i){
                        if(dp[i][S - A[i]]){
                                ans.push_back('H');
                                S -= A[i];
                        }else if(dp[i][S - B[i]]){
                                ans.push_back('T');
                                S -= B[i];
                        }
                }
                reverse(ans.begin() , ans.end());
                cout << ans;
        }else{
                cout << "No";
        }

        return 0;
}
