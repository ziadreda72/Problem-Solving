#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

int32_t main(){
        ios::sync_with_stdio(false);
        cin.tie(nullptr);

        string s;
        cin >> s;

        int N = (int) s.size();
        vector pref(10 , vector < int > (N + 1 , 0));
        for(char i = '0' ; i <= '9' ; ++i){
                for(int j = 1 ; j <= N ; ++j){
                        pref[i - '0'][j] += pref[i - '0'][j - 1] + (s[j - 1] == i);
                }
        }

        map < string , int > mp;
        for(int i = 0 ; i <= N ; ++i){
                string b;
                for(int j = 0 ; j <= 9 ; ++j){
                        b += char((pref[j][i] % 2) + '0');
                }
                mp[b]++;
        }
        
        i64 ans = 0;
        for(auto [key , val] : mp){
                ans += 1LL * val * (val - 1) / 2;
        }

        cout << ans;

        return 0;
}
