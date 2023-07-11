#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

set < i64 > st;

void solveTC() {
        int n;
        cin >> n;
        cout << (st.contains(n) ? "YES" : "NO");
}

int32_t main() {
        ios::sync_with_stdio(false);cin.tie(nullptr);
        cout.tie(nullptr);cout.precision(20);
        for (int k = 2;; ++k) {
                i64 sum = k + 1 , cur = k * k;
                if(sum + cur > 1e6)
                        break;
                while (sum + cur <= 1e6){
                        sum += cur;
                        st.insert(sum);
                        cur *= k;
                }
        }
        int tc = 1;
        cin >> tc;
        while(tc--){
                solveTC();
                cout << '\n';
        }
        return 0;
}
