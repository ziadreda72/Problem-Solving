#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

int32_t main(){
        ios::sync_with_stdio(false);
        cin.tie(nullptr);

        set < i64 > st;
        for(int i = 1 ; i <= 9 ; ++i){
                for(int j = -9 ; j <= 9 ; ++j){
                        i64 num = 0;
                        int d = i;
                        for(int k = 0 ; k < 18 ; ++k){
                                num = 10 * num + d;
                                st.insert(num);
                                d += j;
                                if(!(0 <= d && d <= 9)) break;
                        }
                }
        }

        i64 X;
        cin >> X;

        cout << *st.lower_bound(X);

        return 0;
}
