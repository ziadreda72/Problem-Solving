#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

int32_t main(){
        ios::sync_with_stdio(false);
        cin.tie(nullptr);

        string s;
        cin >> s;
        int n = (int) s.size();


        string t;
        cin >> t;
        int m = (int) t.size(); 

        vector < string > ans;

        for(int i = 0 ; i + m <= n ; ++i){
                bool ok = 1;
                for(int j = 0 ; j < m ; ++j){
                        if(s[i + j] != '?'){
                                ok &= s[i + j] == t[j];
                        }
                }

                if(ok){
                        string s2 = s;
                        for(int j = 0 ; j < m ; ++j){
                                s2[i + j] = t[j];
                        }
                        for(auto &c : s2){
                                if(c == '?') c = 'a';
                        }
                        ans.push_back(s2);
                }
        }

        if(ans.empty()){
                cout << "UNRESTORABLE";
                return 0;
        }

        sort(ans.begin() , ans.end());

        cout << ans[0];

        return 0;
}
