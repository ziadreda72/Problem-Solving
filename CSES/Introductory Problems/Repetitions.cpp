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
        char cur = s[0];
        int cnt = 0 , ans = 0;
        for(int i = 0 ; i < (int) s.size() ; ++i){
                if(s[i] == cur){
                        cnt++;
                }else{
                        ans = max(ans , cnt);
                        cnt = 1;
                        cur = s[i];
                }
        }
        ans = max(ans , cnt);
        cout << ans;
        return 0;
}
