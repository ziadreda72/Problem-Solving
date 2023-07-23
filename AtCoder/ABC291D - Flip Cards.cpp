#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

const int P = 998244353 , N = (int) 2e5 + 5;

int add(int x , int y){
        x %= P;
        y %= P;
        return 1LL * (x + y) % P;
}

int n;
int a[N][2] , dp[N][2];

int32_t main() {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        cin >> n;
        for (int i = 0; i < n; ++i) {
                cin >> a[i][0] >> a[i][1];
        }
        dp[0][0] = dp[0][1] = 1;
        for (int i = 0; i + 1 < n; ++i) {
                for(int x : {0 , 1}){
                        for(int y : {0 , 1}){
                                if(a[i][x] != a[i + 1][y]){
                                        dp[i + 1][y] = add(dp[i + 1][y] , dp[i][x]);
                                }
                        }
                }
        }
        cout << add(dp[n - 1][0] , dp[n - 1][1]);
	return 0;
}
