#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

void solveTC(){
        int n , q;
        cin >> n >> q;

        vector < i64 > a(n);
        for(int i = 0 ; i < n ; ++i) cin >> a[i];

        vector < set < int > > st(31);
        for(int i = 1 ; i <= 30 ; ++i){
                for(int j = 0 ; j < n ; ++j){
                        if(a[j] % (1LL << i) == 0){
                                st[i].insert(j);
                        }
                }
        }

        while(q--){
                int x;
                cin >> x;

                for(auto i : st[x]){
                        a[i] += (1LL << (x - 1));
                        st[x - 1].insert(i);
                        for(int j = 30 ; j > x ; --j){
                                if(st[j].count(i)){
                                        st[j].erase(i);
                                }
                        }
                }
                st[x].clear();
        }

        for(auto x : a) cout << x << ' ';
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
