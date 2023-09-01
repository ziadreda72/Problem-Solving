#include <bits/stdc++.h>

using namespace std;
using i64 = long long;
using ld = long double;

#define F first
#define S second

int32_t main(){
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        int n;
        cin >> n;
        vector < vector < int > > pos(n + 1);
        for(int i = 1 ; i <= n ; ++i){
                int a;
                cin >> a;
                pos[a].push_back(i);
        }
        int Q;
        cin >> Q;
        while(Q--){
                int l , r , x;
                cin >> l >> r >> x;
                auto L = lower_bound(pos[x].begin() , pos[x].end() , l) - pos[x].begin();
                auto R = upper_bound(pos[x].begin() , pos[x].end() , r) - pos[x].begin();
                cout << R - L << '\n';
        }
        return 0;
}
