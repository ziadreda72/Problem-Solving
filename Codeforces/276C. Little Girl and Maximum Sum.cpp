#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

struct query{
        int l , r;

        query(){}

        query(int l , int r): l(l) , r(r){}
};

int32_t main() {
        ios::sync_with_stdio(false);cin.tie(nullptr);
        cout.tie(nullptr);cout.precision(20);
        int n , q;
        cin >> n >> q;
        vector < int > a(n + 1);
        for (int i = 1; i <= n; ++i) {
                cin >> a[i];
        }

        vector < query > queries(q);
        vector < int > par(n + 1 , 0) , pref_par(n + 1 , 0);
        for (int i = 0; i < q; ++i) {
                cin >> queries[i].l >> queries[i].r;
                par[queries[i].l]++;
                if(queries[i].r + 1 <= n)
                        par[queries[i].r + 1]--;
        }
        for (int i = 1; i <= n; ++i) {
                pref_par[i] += pref_par[i - 1] + par[i];
        }
        vector < pair < int , int > > v;
        vector < int > v2;
        for (int i = 1; i <= n; ++i) {
                v.emplace_back(pref_par[i] , i);
                v2.push_back(a[i]);
        }
        sort(v.begin(), v.end());
        sort(v2.begin(), v2.end());
        while (!v.empty()){
                int i = v.back().second;
                a[i] = v2.back();
                v.pop_back();
                v2.pop_back();
        }
        i64 ans = 0;
        vector < i64 > pref(n + 1 , 0LL);
        for (int i = 1; i <= n; ++i) {
                pref[i] += pref[i - 1] + a[i];
        }
        for(auto query : queries){
                int l = query.l , r = query.r;
                ans += pref[r] - pref[l - 1];
        }
        cout << ans;
        return 0;
}
