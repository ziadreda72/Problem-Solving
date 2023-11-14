#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

int32_t main(){
        ios::sync_with_stdio(false);
        cin.tie(nullptr);

        int N;
        cin >> N;

        string s;
        cin >> s;

        vector < int > pref(N , 0);

        pref[0] = s[0] == 'W';
        for(int i = 1 ; i < N ; ++i){
                pref[i] = pref[i - 1] + (s[i] == 'W');
        }

        vector < int > suf(N , 0);

        suf[N - 1] = s.back() == 'E';
        for(int i = N - 2 ; i >= 0 ; --i){
                suf[i] = suf[i + 1] + (s[i] == 'E');
        }

        int ans = min(suf[1] , pref[N - 2]);

        for(int i = 1 ; i + 1 < N ; ++i){
                ans = min(ans , pref[i - 1] + suf[i + 1]);
        }

        cout << ans;

        return 0;
}
