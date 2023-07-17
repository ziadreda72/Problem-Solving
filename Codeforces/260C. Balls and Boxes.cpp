#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

struct segtree {
        int sz;
        vector < int > mn;

        void init(int n){
                sz = 1;
                while (sz < n)
                        sz *= 2;
                mn.assign(2 * sz , INT32_MAX);
        }

        void build(vector < int > &a , int x , int lx , int rx){
                if(rx - lx == 1){
                        if (lx < (int) a.size())
                                mn[x] = a[lx];
                        return;
                }
                int m = (lx + rx) / 2;
                build(a , 2 * x + 1 , lx , m);
                build(a , 2 * x + 2 , m , rx);
                mn[x] = min(mn[2 * x + 1] , mn[2 * x + 2]);
        }

        void build(vector < int > &a){
                build(a , 0 , 0 , sz);
        }

        void update(int i , int v , int x , int lx , int rx){
                if(rx - lx == 1){
                        mn[x] = v;
                        return;
                }
                int m = (lx + rx) / 2;
                if(i < m)
                        update(i, v, 2 * x + 1, lx, m);
                else
                        update(i, v, 2 * x + 2, m, rx);
                mn[x] = min(mn[2 * x + 1] , mn[2 * x + 2]);
        }

        void update(int i , int v){
                update(i, v, 0, 0, sz);
        }

        int get(int l , int r , int x , int lx , int rx){
                if(lx >= r || l >= rx)
                        return INT32_MAX;
                if(l <= lx && rx <= r)
                        return mn[x];
                int m = (lx + rx) / 2;
                return min(get(l , r , 2 * x + 1 , lx , m) , get(l , r , 2 * x + 2 , m , rx));
        }

        int get(int l , int r){
                return get(l , r , 0 , 0 , sz);
        }
};

int32_t main() {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        int n , en;
        cin >> n >> en;
        en--;
        vector < int > a(n);
        int mn = INT32_MAX;
        for (int i = 0; i < n; ++i) {
                cin >> a[i];
                mn = min(mn , a[i]);
        }
        vector < int > v;
        for (int i = 0; i < n; ++i) {
                if(a[i] == mn)
                        v.push_back(i);
        }
        segtree seg;
        seg.init(n);
        seg.build(a);
        vector < i64 > ans(n);
        for(auto st : v){
                if(min(seg.get(0 , st) , seg.get(st + 1 , n)) - a[st] >= 0){
                        if(st == en){
                                ans[st] = 1LL * a[st] * n;
                                for (int i = 0; i < n; ++i) {
                                        if(i == st)
                                                continue;
                                        ans[i] = a[i] - a[st];
                                }
                                for (int i = 0; i < n; ++i) {
                                        cout << ans[i] << ' ';
                                }
                                return 0;
                        }
                        if(en > st){
                                if(seg.get(st + 1 , en + 1) - a[st] - 1 >= 0){
                                        ans[st] = (1LL * a[st] * n) + (en - st);
                                        for (int i = 0; i < n; ++i) {
                                                if(i == st)
                                                        continue;
                                                ans[i] = a[i] - a[st];
                                        }
                                        for (int i = st + 1; i <= en; ++i) {
                                                ans[i]--;
                                        }
                                        for (int i = 0; i < n; ++i) {
                                                cout << ans[i] << ' ';
                                        }
                                        return 0;
                                }
                        }
                        if(en < st){
                                if(min(seg.get(0 , en + 1) , seg.get(st + 1 , n)) - a[st] - 1 >= 0){
                                        ans[st] = (1LL * a[st] * n) + (en + 1) + (n - st - 1);
                                        for (int i = 0; i < n; ++i) {
                                                if(i == st)
                                                        continue;
                                                ans[i] = a[i] - a[st];
                                        }
                                        for (int i = 0; i <= en; ++i) {
                                                ans[i]--;
                                        }
                                        for (int i = st + 1; i < n; ++i) {
                                                ans[i]--;
                                        }
                                        for (int i = 0; i < n; ++i) {
                                                cout << ans[i] << ' ';
                                        }
                                        return 0;
                                }
                        }
                }
        }
        return 0;
}
