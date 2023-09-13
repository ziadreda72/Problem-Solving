#include <bits/stdc++.h>

using namespace std;
using i64 = long long;
using ld = long double;

#define F first
#define S second

const int INF = INT_MAX;

int SQRT(int x){
        int lo = 0 , hi = 400;
        while(hi - lo > 1){
                int mid = (lo + hi) >> 1;
                if(mid * mid >= x){
                        hi = mid;
                }else{
                        lo = mid;
                }
        }
        return hi;
}

int32_t main(){
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        int n;
        cin >> n;
        int SQ = SQRT(n);
        vector < int > a(n) , b(SQ , INF);
        for(int i = 0 ; i < n ; ++i){
                cin >> a[i];
                int k = i / SQ;
                b[k] = min(b[k] , a[i]);
        }
        int Q;
        cin >> Q;
        for(int q = 0 ; q < Q ; ++q){
                int l , r;
                cin >> l >> r;
                int ans = INF;
                int c_l = l / SQ , c_r = r / SQ;
                if(c_l == c_r){
                        for(int i = l ; i <= r ; ++i){
                                ans = min(ans , a[i]);
                        }
                        cout << ans << '\n';
                        continue;
                }
                for(int i = l , en = (c_l + 1) * SQ - 1 ; i <= en ; ++i){
                        ans = min(ans , a[i]);
                }
                for(int i = c_l + 1 ; i < c_r ; ++i){
                        ans = min(ans , b[i]);
                }
                for(int i = c_r * SQ ; i <= r ; ++i){
                        ans = min(ans , a[i]);
                }
                cout << ans << '\n';
        }
        return 0;
}
