#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

int calc(string &s , string& t) {
        int ret = 0;
        for (int i = 0 ; i < (int) s.size() && ret < (int) t.size() ; ++i)
                if(s[i] == t[ret]) ret++; 
        return ret;
}

int32_t main() {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);

        int n;
        cin >> n;

        string t;
        cin >> t;

        vector < string > s(n);
        for (int i = 0 ; i < n ; ++i) cin >> s[i];

        vector < int > a(n , 0);
        for (int i = 0 ; i < n ; ++i) a[i] = calc(s[i] , t);

        reverse(t.begin() , t.end());

        vector < i64 > suf((int) t.size() + 1 , 0LL);
        for (int i = 0 ; i < n ; ++i) {
                reverse(s[i].begin() , s[i].end());
                suf[calc(s[i] , t)]++;
        }

        for (int i = (int) t.size() - 1 ; i >= 0 ; --i) suf[i] += suf[i + 1];

        i64 ans = 0;
        for (int i = 0 ; i < n ; ++i)
                ans += suf[max(0 , (int) t.size() - a[i])];
        cout << ans;

        return 0;
}
