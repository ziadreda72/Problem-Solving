#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

int32_t main(){
        ios::sync_with_stdio(false);
        cin.tie(nullptr);

        int N;
        cin >> N;
        
        vector < string > s(N);
        for(int i = 0 ; i < N ; ++i) cin >> s[i];

        vector cnt(N , vector < int > (26 , 0));
        for(int i = 0 ; i < N ; ++i){
                for(auto c : s[i]){
                        cnt[i][c - 'a']++;
                }
        }

        string ans;
        for(int i = 0 ; i < 26 ; ++i){
                int mn = 10000;
                for(int j = 0 ; j < N ; ++j){
                        mn = min(mn , cnt[j][i]);
                }
                ans += string(mn , char(i + 'a'));
        }

        cout << ans;

        return 0;
}
