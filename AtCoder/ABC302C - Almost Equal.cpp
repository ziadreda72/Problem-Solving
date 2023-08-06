#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

int32_t main(){
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        int n , m;
        cin >> n >> m;
        vector < string > s(n);
        for (int i = 0; i < n; ++i) {
                cin >> s[i];
        }
        sort(s.begin(), s.end());
        do {
                bool ok = 1;
                for (int i = 0; i + 1 < n; ++i) {
                        int cnt = 0;
                        for (int j = 0; j < m; ++j) {
                                cnt += s[i][j] != s[i + 1][j];
                        }
                        ok &= cnt <= 1;
                }
                if(ok){
                        cout << "Yes";
                        return 0;
                }
        } while (next_permutation(s.begin(), s.end()));
        cout << "No";
        return 0;
}
