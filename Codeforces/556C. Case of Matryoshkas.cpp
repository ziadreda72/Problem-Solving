    #include <bits/stdc++.h>

    using namespace std;

    using i64 = long long;

    #define F first
    #define S second

    int32_t main() {
        ios::sync_with_stdio(false);cin.tie(nullptr);
        cout.tie(nullptr);cout.precision(20);
        int n , k;
        cin >> n >> k;
        int ans = 0;
        vector < vector < int > > a;
        while (k--){
            int m;
            cin >> m;
            vector < int > v;
            for (int i = 0; i < m; ++i) {
                int x;
                cin >> x;
                v.push_back(x);
            }
            a.push_back(v);
        }
        sort(a.begin(), a.end());
        for (int i = 1; i < (int) a[0].size(); ++i) {
            if(a[0][i] - a[0][i - 1] == 1)
                continue;
            for (int j = i; j < (int) a[0].size(); ++j) {
                ans += 2;
            }
            break;
        }
        for (int i = 1; i < (int) a.size(); ++i) {
            ans += ((int) a[i].size() - 1) * 2 + 1;
        }
        cout << ans;
        return 0;
    }
