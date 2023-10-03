#include <bits/stdc++.h>

using namespace std;
using i64 = long long;
using ld = long double;

#define F first
#define S second

const int N = (1 << 20);

i64 A[N];
set < int > st;

int32_t main(){
        ios::sync_with_stdio(false);
        cin.tie(nullptr);

        memset(A , -1 , sizeof A);

        for(int i = 0 ; i < N ; ++i) st.insert(i);

        int Q;
        cin >> Q;

        while(Q--){
                int t;
                i64 x;
                cin >> t >> x;

                if(t == 1){
                        int h = x % N;

                        auto it = st.lower_bound(h);
                        if(it == st.end()){
                                it = st.begin();
                        }
                        A[*it] = x;
                        st.erase(it);
                }else{
                        int h = x % N;
                        cout << A[h] << '\n';
                }
        }

        return 0;
}
