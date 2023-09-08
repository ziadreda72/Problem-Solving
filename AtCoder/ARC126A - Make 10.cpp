#include <bits/stdc++.h>

using namespace std;
using i64 = long long;
using ld = long double;

#define F first
#define S second

void solveTC(){
        i64 n2 , n4 , n6 , mn , ans;
        cin >> n2 >> n6 >> n4;
        n6 /= 2;
        
        mn = min(n6 , n4);
        ans = mn;
        n6 -= mn , n4 -= mn;

        mn = min(n6 , n2 / 2);
        ans += mn;
        n6 -= mn , n2 -= 2 * mn;

        mn = min(n4 / 2 , n2);
        ans += mn;
        n4 -= 2 * mn , n2 -= mn;

        mn = min(n4 , n2 / 3);
        ans += mn;
        n2 -= 3 * mn;

        ans += n2 / 5;

        cout << ans;
}

int32_t main(){
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        int tc;
        cin >> tc;
        while (tc--){
                solveTC();
                cout << '\n';
        }
        return 0;
}
