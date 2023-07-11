#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

const i64 inf = 1e18;

set < i64 > st;

void pre(){
        for (i64 k = 2;; ++k) {
                i64 val = 1 , p = k;
                val += p;
                p *= k;
                val += p;
                p *= k;
                val += p;
                if(val > inf)
                        break;
                while (1){
                        st.insert(val);
                        if(p > inf / k + 1)
                                break;
                        p *= k;
                        val += p;
                        if(val > inf)
                                break;
                        st.insert(val);
                }
        }
}

bool check(i64 n){
        i64 lo = 2 , hi = 1e9;
        while (lo <= hi){
                i64 mid = (lo + hi) / 2;
                i64 x = mid * mid + mid + 1;
                if(x > n)
                        hi = mid - 1;
                else if(x < n)
                        lo = mid + 1;
                else
                        return true;
        }
        return false;
}

void solveTC() {
        i64 n;
        cin >> n;
        if(st.contains(n) || check(n))
                cout << "YES";
        else
                cout << "NO";
}

int32_t main() {
        ios::sync_with_stdio(false);cin.tie(nullptr);
        cout.tie(nullptr);cout.precision(20);
        pre();
        int tc = 1;
        cin >> tc;
        while(tc--){
                solveTC();
                cout << '\n';
        }
        return 0;
}
