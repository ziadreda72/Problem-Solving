#include <bits/stdc++.h>

using namespace std;
using i64 = long long;
using i128 = __int128;
using ld = long double;

#define F first
#define S second

int32_t main(){
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        string s;
        cin >> s;
        int b = 0;
        i64 ans = 0;
        for(auto c : s){
                if(c == 'B')
                        b++;
                else
                        ans += b;
        }
        cout << ans;
        return 0;
}
