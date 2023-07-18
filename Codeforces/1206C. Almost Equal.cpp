#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

int32_t main() {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        int n;
        cin >> n;
        if(n % 2 == 0){
                cout << "NO";
                return 0;
        }
        cout << "YES\n";
        vector < int > a(2 * n +1);
        int l = 1 , r = 2 * n;
        for (int i = 1; i + n <= 2 * n; ++i) {
                if(i & 1){
                        a[i] = l++;
                        a[i + n] = l++;
                }else{
                        a[i] = r--;
                        a[i + n] = r--;
                }
        }
        for (int i = 1; i <= 2 * n; ++i) {
                cout << a[i] << ' ';
        }
	return 0;
}
