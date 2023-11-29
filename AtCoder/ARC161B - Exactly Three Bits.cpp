#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

set < i64 > st;

void solveTC(){
        i64 N;
        cin >> N;

        if(N < 7){
                cout << -1;
                return;
        }

        auto it = st.upper_bound(N);

        cout << *prev(it);
}

int32_t main(){
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        
        for(int i = 0 ; i < 60 ; ++i){
                for(int j = i + 1 ; j < 60 ; ++j){
                        for(int k = j + 1 ; k < 60 ; ++k){
                                i64 x = (1LL << i) + (1LL << j) + (1LL << k);
                                st.insert(x);
                        }
                }
        }

        int tc;
        cin >> tc;
        
        while (tc--){
                solveTC();
                cout << '\n';
        }
        
        return 0;
}
