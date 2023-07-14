#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

int32_t main() {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        int n , m;
        while (cin >> n >> m && n){
                i64 sum = 0;
                vector < i64 > a(n);
                for (int i = 0; i < n; ++i) {
                        for (int j = 0; j < m; ++j) {
                                int x;
                                cin >> x;
                                if(j == m - 1)
                                        a[i] = x , sum += x;
                        }
                }
                for (int i = 0; i < n; ++i) {
                        if(a[i] == 0){
                                cout << "0 / 1\n";
                                continue;
                        }
                        i64 g = __gcd(a[i] , sum);
                        a[i] /= g;
                        cout << a[i] << " / " << sum / g << '\n';
                }
        }
        return 0;
}
