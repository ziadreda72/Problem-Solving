#include <bits/stdc++.h>

using namespace std;
using i64 = long long;
using ld = long double;

#define F first
#define S second

int32_t main(){
        ios::sync_with_stdio(false);
        cin.tie(nullptr);

        string s;
        cin >> s;

        int n = (int) s.size();
        vector < int > pref(n , 0);
        pref[0] = s[0] - '0'; 
        for(int i = 1 ; i < n ; ++i) pref[i] += pref[i - 1] + (s[i] - '0');

        vector < int > ans(n);
        int carry = 0;
        for(int i = n - 1 ; i >= 0 ; --i){
                ans[i] = (pref[i] + carry) % 10;
                carry = (pref[i] + carry) / 10;
        }

        if(carry) cout << carry;
        for(int x : ans) cout << x;

        return 0;
}
