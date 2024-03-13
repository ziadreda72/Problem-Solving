#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

void solveTC(){
        int n;
        cin >> n;

        string s;
        cin >> s;

        set < char > st;

        i64 ans = 0;
        for (int i = 0 ; i < n ; ++i) {
                st.insert(s[i]);
                ans += st.size(); 
        }

        cout << ans;
}

int32_t main(){
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        
        int tc;
        cin >> tc;
        
        while (tc--){
                solveTC();
                cout << '\n';
        }
        
        return 0;
}
