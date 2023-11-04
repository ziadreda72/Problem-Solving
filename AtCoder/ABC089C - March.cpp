#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

int32_t main(){
        ios::sync_with_stdio(false);
        cin.tie(nullptr);

        static const string MARCH = "MARCH";

        int N;
        cin >> N;

        string s;
        for(int i = 0 ; i < N ; ++i){
                string str;
                cin >> str;

                if(MARCH.find(str[0]) != string::npos){
                        s.push_back(str[0]);
                }
        }

        N = (int) s.size();

        if(N < 3){
                cout << 0;
                return 0;
        }

        map < char , vector < int > > mp;

        for(auto c : MARCH){
                mp[c].assign(N , 0);

                mp[c][0] = s[0] == c;
                for(int i = 1 ; i < N ; ++i){
                        mp[c][i] += mp[c][i - 1] + (s[i] == c);
                }
        }

        i64 ans = 0;
        for(int i = 1 ; i + 1 < N ; ++i){
                i64 x = 0;
                for(auto c : MARCH){
                        if(c == s[i]) continue;
                        for(auto c2 : MARCH){
                                if(c2 == s[i] || c2 == c) continue;

                                ans += 1LL * mp[c][i - 1] * (mp[c2].back() - mp[c2][i]);
                        }
                }
        }

        cout << ans;

        return 0;
}
