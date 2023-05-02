#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

#define F first
#define S second

int32_t main() {
    ios::sync_with_stdio(false);cin.tie(nullptr);
    cout.tie(nullptr);cout.precision(20);
    int n , q;
    cin >> n >> q;
    vector < queue < int > > v(n);
    int cur_time = 1;
    set < pair < int , int > > st;
    while (q--){
        int t , x;
        cin >> t >> x;
        if(t == 1){
            x--;
            v[x].push(cur_time);
            st.emplace(cur_time , x);
            cur_time++;
        }else if(t == 2){
            x--;
            while ((int) v[x].size()){
                if(st.find({v[x].front(), x}) != st.end()){
                    st.erase(st.find({v[x].front(), x}));
                }
                v[x].pop();
            }
        }else{
            set < pair < int , int > > st2;
            for(auto p : st){
                if(p.F <= x) st2.insert(p);
                else break;
            }
            for(auto p : st2) st.erase(p);
        }
        cout << (int) st.size() << '\n';
    }
    return 0;
}
