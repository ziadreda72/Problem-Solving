#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

int32_t main(){
        ios::sync_with_stdio(false);
        cin.tie(nullptr);

        int N , M , L;
        cin >> N >> M >> L;

        vector < i64 > a(N);
        for(int i = 0 ; i < N ; ++i) cin >> a[i];

        vector < i64 > b(M);
        for(int i = 0 ; i < M ; ++i) cin >> b[i];

        map < int , vector < int > > g;
        while(L--){
                int u , v;
                cin >> u >> v;
                g[--u].push_back(--v);
        }

        multiset < i64 > mst(b.begin() , b.end());

        i64 ans = INT64_MIN;

        for(int i = 0 ; i < N ; ++i){
                if(g.count(i)) continue;
                ans = max(ans , a[i] + *mst.rbegin());
        }

        for(auto [u , v] : g){
                for(auto i : v) mst.erase(mst.find(b[i]));
                if(mst.empty()){
                        for(auto i : v) mst.insert(b[i]);
                        continue;
                }else{
                        ans = max(ans , a[u] + *mst.rbegin());
                        for(auto i : v) mst.insert(b[i]);
                }
        }

        cout << ans;

        return 0;
}
