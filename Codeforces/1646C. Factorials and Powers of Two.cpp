#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

const i64 MAX = (i64) 1e12;

int N;
vector < i64 > v;

void solveTC() {
    i64 n;
    cin >> n;
    int ans = __builtin_popcountll(n);
    for (int msk = 0; msk < (1 << N); ++msk) {
        i64 sum = 0;
        for (int j = 0; j < N; ++j) {
            if((1 << j) & msk)
                sum += v[j];
        }
        if(sum > n)
            continue;
        ans = min(ans , __builtin_popcountll(msk) + __builtin_popcountll(n - sum));
    }
    if(ans == INT32_MAX)
        ans = -1;
    cout << ans;
}

int32_t main() {
    ios::sync_with_stdio(false);cin.tie(nullptr);
    cout.tie(nullptr);cout.precision(20);
    i64 x = 6 , cur = 4;
    while (x <= MAX){
        v.push_back(x);
        x *= cur;
        cur++;
    }
    N = (int) v.size();
    int tc = 1;
    cin >> tc;
    while(tc--){
        solveTC();
        cout << '\n';
    }
    return 0;
}
