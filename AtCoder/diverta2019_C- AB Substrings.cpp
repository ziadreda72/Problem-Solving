#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

int32_t main(){
        ios::sync_with_stdio(false);
        cin.tie(nullptr);

        int n;
        cin >> n;

        int ans = 0 , c1 = 0 , c2 = 0 , c3 = 0;
        for(int i = 0 ; i < n ; ++i){
                string s;
                cin >> s;
                
                for(int i = 0 ; i + 1 < (int) s.size() ; ++i) ans += s[i] == 'A' && s[i + 1] == 'B';

                if(s[0] == 'B' && s.back() == 'A') c1++;
                else if(s[0] == 'B') c2++;
                else if(s.back() == 'A') c3++;
        }

        if(c1 == 0) ans += min(c2 , c3);
        else{
                if(c2 + c3 == 0) ans += c1 - 1;
                else ans += c1 + min(c2 , c3);
        }

        cout << ans;

        return 0;
}
