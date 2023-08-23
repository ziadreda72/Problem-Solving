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
        int ans = 0;
        for(int i = 0 ; i <= 9999 ; ++i){
                string pin = to_string(i);
                while(pin.size() < 4)
                        pin.push_back('0');
                bool ok = 1;
                for(int i = 0 ; i <= 9 ; ++i){
                        char c = char('0' + i);
                        if(s[i] == 'o')
                                ok &= pin.find(c) != -1;
                        if(s[i] == 'x')
                                ok &= pin.find(c) == -1;

                }
                ans += ok;
        }
        cout << ans;
        return 0;
}
