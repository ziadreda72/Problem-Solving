#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

int32_t main(){
        ios::sync_with_stdio(false);
        cin.tie(nullptr);

        int Q;
        cin >> Q;

        queue < int > q;

        multiset < int > st;

        while(Q--){
                int t;
                cin >> t;

                if(t == 1){
                        int x;
                        cin >> x;

                        q.push(x);
                }

                if(t == 2){
                        if(st.empty()){
                                cout << q.front() << '\n';
                                q.pop();
                        }else{
                                cout << *st.begin() << '\n';
                                st.erase(st.begin());
                        }
                }

                if(t == 3){
                        while(q.size()){
                                st.insert(q.front());
                                q.pop();
                        }
                }
        }

        return 0;
}
