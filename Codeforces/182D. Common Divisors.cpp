#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

int n , m;
string a , b;

bool ok(string s , int x){
        for (int i = 0; i < (int) s.size(); ++i) {
                if(s[i] != s[i % x])
                        return 0;
        }
        return 1;
}

int32_t main() {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        cin >> a >> b;
        n = (int) a.size() , m = (int) b.size();
        int ans = 0;
        for (int i = 1; i <= min(n , m); ++i) {
                if(n % i == 0 && m % i == 0){
                        ans += ok(a , i) && ok(b , i) && (a.substr(0 , i) == b.substr(0 , i));
                }
        }
        cout << ans;
        return 0;
}
