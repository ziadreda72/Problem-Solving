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

        int S = count(s.begin() , s.end() , '1');

        vector < array < int , 2 > > w(N);
        set < int > st;
        vector < int > w2;

        for(int i = 0 ; i < N ; ++i){
                cin >> w[i][0];
                w[i][1] = s[i] - '0';
                st.insert(w[i][0]);
                w2.push_back(w[i][0]);
        }

        sort(w.begin() , w.end());
        sort(w2.begin() , w2.end());

        vector < int > pref(N);
        pref[0] = w[0][1];
        for(int i = 1 ; i < N ; ++i) pref[i] += pref[i - 1] + w[i][1];

        int ans = S;
        for(auto x : st){
                int i = upper_bound(w2.begin() , w2.end() , x) - w2.begin();
                ans = max(ans , (i - pref[i - 1]) + (S - pref[i - 1]));
        }

        cout << ans;

        return 0;
}
