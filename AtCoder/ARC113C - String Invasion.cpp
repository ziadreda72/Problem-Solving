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
        map < char , int > mp;
        i64 ans = 0;
        for(int i = n - 1 ; i >= 0 ; --i){
                if(i + 2 < n && s[i] == s[i + 1] && s[i] != s[i + 2]){
                        ans += n - i - 2 - (mp[s[i]] - 1);
                        mp.clear();
                        mp[s[i]] = n - i;
                }
                else{
                        mp[s[i]]++;
                }   
        }
        cout << ans;
        return 0;
}
