#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

const int N = 20;

int n;
vector < int > a;
i64 dp[N][4][2];

i64 solve(int i , int cnt , int f){
        if(i >= n)
                return 1;
        auto &ret = dp[i][cnt][f];
        if(ret != -1)
                return ret;
        ret = 0;
        int MAX = f ? 9 : a[i];
        for (int d = 0; d <= MAX; ++d) {
                if(cnt + (d > 0) <= 3)
                        ret += solve(i + 1 , cnt + (d > 0) , f | (d < MAX));
        }
        return ret;
}

void solveTC() {
        i64 l , r;
        cin >> l >> r;
        a.clear();
        while (r){
                a.push_back(r % 10);
                r /= 10;
        }
        reverse(a.begin(), a.end());
        i64 ans = 0;
        memset(dp , -1 , sizeof dp);
        n = (int) a.size();
        ans += solve(0 , 0 , 0);
        a.clear();
        l--;
        while (l){
                a.push_back(l % 10);
                l /= 10;
        }
        reverse(a.begin(), a.end());
        memset(dp , -1 , sizeof dp);
        n = (int) a.size();
        ans -= solve(0 , 0 , 0);
        cout << ans;
}

int32_t main() {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        int tc = 1;
        cin >> tc;
        while(tc--){
                solveTC();
                cout << '\n';
        }
        return 0;
}
