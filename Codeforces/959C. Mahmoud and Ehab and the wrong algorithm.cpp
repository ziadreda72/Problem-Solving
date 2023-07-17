#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

const int N = (int) 1e5 + 10;

int n;

int32_t main() {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        cin >> n;
        if(n < 6){
                cout << "-1\n";
        }else{
                cout << "1 2\n1 3\n1 4\n";
                for (int i = 5; i <= n; ++i) {
                        cout << 2 << ' ' << i << '\n';
                }
        }
        for (int i = 1; i + 1 <= n; ++i)
                cout << i << ' ' << i + 1 << '\n';
        return 0;
}
