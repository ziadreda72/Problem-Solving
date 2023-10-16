#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

map < i64 , i64 > dp;

i64 solve(i64 N){
        if(!N){
                return 1;
        }

        if(dp.count(N)){
                return dp[N];
        }

        return dp[N] = solve(N / 2) + solve(N / 3);
}

int32_t main(){
        ios::sync_with_stdio(false);
        cin.tie(nullptr);

        i64 N;
        cin >> N;

        cout << solve(N);

        return 0;
}
